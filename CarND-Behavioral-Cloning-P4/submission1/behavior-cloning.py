# import packages
import csv
import cv2    
import numpy as np
from keras.models import Sequential
from keras.layers import Flatten, Dense, Activation, Dropout, Lambda, Cropping2D
from keras.layers.convolutional import Conv2D
from keras.layers.pooling import MaxPooling2D
from keras.callbacks import ModelCheckpoint, EarlyStopping
from keras import optimizers
from PIL import Image
import matplotlib.pyplot as plt

# load center, left and right images
i = 0
images = []
measurements = []
with open('./data/run2/driving_log.csv') as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        
        source_path = row[0]
        filename = source_path.split('/')[-1]
        filename_center = '../data/run2/IMG/' + filename
        
        source_path = row[1]
        filename = source_path.split('/')[-1]
        filename_left = '../data/run2/IMG/' + filename        
        
        source_path = row[2]
        filename = source_path.split('/')[-1]
        filename_right = '../data/run2/IMG/' + filename        
        
        steering_center = float(row[3])
        
        # create adjusted steering measurements for the side camera images
        correction = 0.25 # this is a parameter to tune
        steering_left = steering_center + correction
        steering_right = steering_center - correction

        # read in images from center, left and right cameras
        img_center = np.asarray(Image.open(filename_center))
        img_left = np.asarray(Image.open(filename_left))
        img_right = np.asarray(Image.open(filename_right))

        # add images and angles to data set
        images.extend([img_center, img_left, img_right])
        measurements.extend([steering_center, steering_left, steering_right])

        if i%200 == 0:
            print('processing row = ' + str(i))
        i+=1
        
# augment data by flipping image    
augmented_images, augmented_measurements  = [], []
for image, measurement in zip(images, measurements):
    augmented_images.append(image)
    augmented_measurements.append(measurement)
    augmented_images.append(cv2.flip(image,1))
    augmented_measurements.append(measurement*(-1.0))

# create training data
X_train = np.array(augmented_images)
y_train = np.array(augmented_measurements)

# model choice
# CHOICE = 0: basic network to see if the network can
#             create a model which can run with the sim
# CHOICE = 1: my neural network inspired by LeNet
CHOICE = 1

if CHOICE == 0:
    model = Sequential()
    model.add(Lambda(lambda x: (x / 255.0) - 0.5, input_shape=(160,320,3)))
    
    model.add(Flatten())    
    model.add(Dense(1))
    
        
if CHOICE == 1:
    model = Sequential()
    
    # data normalization and cropping
    model.add(Lambda(lambda x: (x / 255.0) - 0.5, input_shape=(160,320,3)))
    model.add(Cropping2D(cropping=((70,25),(0,0))))

    # first layer of 6 5x5 convolutional filters with RELU activation
    model.add(Conv2D(6, (5, 5), input_shape=(160, 320, 3)))
    model.add(Activation('relu'))
    # second maxpool layer
    model.add(MaxPooling2D())
    # third dropout layer
    model.add(Dropout(0.5))
    
    # fourth layer of 6 5x5 convolutional filters with RELU activation
    model.add(Conv2D(6, (5, 5)))
    model.add(Activation('relu'))
    # fifth maxpool layer
    model.add(MaxPooling2D())
    # sixth dropout layer
    model.add(Dropout(0.5))      

    # seventh flattening layer
    model.add(Flatten())

    # eighth dense layer of 120 weights and RELU activation
    model.add(Dense(120))
    model.add(Activation('relu'))

    # nineth dense layer of 84 weights and RELU activation
    model.add(Dense(84))
    model.add(Activation('relu'))

    # tenth dense layer of 1 weight
    model.add(Dense(1))

# select optimizer
# add option to select tuning parameters
adam = optimizers.Adam(lr=0.001, beta_1=0.9)
model.compile(loss='mse', optimizer=adam)

# add callbacks for saving best model and early stopping
checkpoint = ModelCheckpoint(filepath='./model.h5', monitor='val_loss', save_best_only=True)
stopper = EarlyStopping(monitor='val_loss', min_delta=0.001, patience=3)

history = model.fit(X_train, y_train, validation_split=0.2, shuffle=True, nb_epoch=10, 
          callbacks=[checkpoint])

#model.save('model.h5')

# plotting loss and validation loss
if False:
    plt.plot(history.history['loss'])
    plt.plot(history.history['val_loss'])
    plt.title('model loss')
    plt.ylabel('loss')
    plt.xlabel('epoch')
    plt.legend(['train', 'validation'], loc='upper right')
    plt.show()