import csv
import cv2

lines = []
with open('../../SDCND-Data/BehavioralCloning/data/driving_log.csv') as csvfile:
    reader = csv.reader(csvfile)
    for line in reader:
        lines.append(line)
        
images = []
measurements = []
i = 0
for line in lines[:100]:
    if i > 0:
        source_path = line[0]
        filename = source_path.split('/')[-1]
        current_path = '../../SDCND-Data/BehavioralCloning/data/IMG/' + filename
        image = cv2.imread(current_path)
        images.append(image)
        measurement = float(line[3])
        measurements.append(measurement)
    i += 1

import numpy as np

X_train = np.array(images)
y_train = np.array(measurements)

if False:
	import matplotlib.pyplot as plt
	plt.figure
	plt.imshow(image)
	plt.show()
	print(image.shape)
	
from keras.models import Sequential
from keras.layers import Flatten, Dense

model = Sequential()
model.add(Flatten(input_shape=(160,320,3)))
model.add(Dense(1))

model.compile(loss='mse', optimizer='adam')
model.fit(X_train, y_train, validation_split=0.2, shuffle=True, nb_epoch=7)

model.save('model.h5')


	
	