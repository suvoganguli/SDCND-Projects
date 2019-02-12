# **Behavioral Cloning** 



**Behavioral Cloning Project**

The goals / steps of this project are the following:
* Use the simulator to collect data of good driving behavior
* Build, a convolution neural network in Keras that predicts steering angles from images
* Train and validate the model with a training and validation set
* Test that the model successfully drives around track one without leaving the road
* Summarize the results with a written report

![carsim](/Users/suvo/Projects/Udacity/SDCND-Projects/CarND-Behavioral-Cloning-P4/carsim.png)

## Rubric Points
### Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/432/view) individually and describe how I addressed each point in my implementation.  

---
### Files Submitted & Code Quality

#### 1. Submission includes all required files and can be used to run the simulator in autonomous mode

My project includes the following files:
* behavior-cloning.py containing the script to create and train the model
* drive.py for driving the car in autonomous mode
* model.h5 containing a trained convolution neural network 
* writeup_report.md summarizing the results

#### 2. Submission includes functional code
Using the Udacity provided simulator and my drive.py file, the car can be driven autonomously around the track by executing 
```sh
python drive.py model.h5
```

#### 3. Submission code is usable and readable

The behavior-cloning.py file contains the code for training and saving the convolution neural network. The file shows the pipeline I used for training and validating the model, and it contains comments to explain how the code works.

### Model Architecture and Training Strategy

#### 1. An appropriate model architecture has been employed

My model was inspired by LeNet and consists of a convolution neural network with the two convolutional layers, maxpool and dropout layers, RELU activation layers and three dense layers at the end.

#### 2. Attempts to reduce overfitting in the model

The model contains dropout layers in order to reduce overfitting (behavior-cloning.py lines 83 and 101). 

#### 3. Model parameter tuning

The model used an adam optimizer. Although it is possible to specify a learning rate,  I found that the default value worked well. (behavior-cloning.py line 119-120).

#### 4. Appropriate training data

Training data was chosen to keep the vehicle driving on the road. I used a combination of center lane driving and recovering from the left and right sides of the road.

For details about how I created the training data, see the next section. 

### Model Architecture and Training Strategy

#### 1. Solution Design Approach

The overall strategy for deriving a model architecture was to try out the LeNet layer and add dropout layers to prevent overfitting and RELU activation layers to introduce nonlinearity.

My first step was to test the code with a basic network with a flattening layer and a dense layer with 1 weight. I ran the simulator with this model. The car moved but it quickly went outside the work. However, this was expected.

Next I created a LeNet like network as mentioned above - without using the left and right images, without data augmentation (flipping images to left and right) and without data cropping. In order to gauge how well the model was working, I split my image and steering angle data into a 80% training and 20% validation set. 

I found that the model worked better in the sense it moved more in a straight line, but it started moving toward the left ledge at the first sharp turn.

Next, I augmented the data by adding flipped images. The behavior improved slightly but this time it went over the right ledge. I tried changing the number of convolutional filters, adding more neurons in the dense layers but the performance didn't improve much.

Next I decided to use the left and the right camera images. I played around with the steering correction factor between 0.2-0.3 but the training and the validation loss didn't change much. I concluded that the model is not very sensitive to the correction factor. I double-checked my hypothesis by running the model with the sim. The model swerved a bit more for higher correction factor but it was not very noticeable.

Finally, I cropped the images to remove the background scenary and the bottom image of the front of the car. This dramatically improved the driving characteristics.

At the end of the process, the vehicle is able to drive autonomously around the track without leaving the road.

#### 2. Final Model Architecture

The final model architecture consisted of a convolution neural network with the following layers and layer sizes:

- Keras lamda layer for data normalization
- Keras cropping layer for cropping first 70 and last 25 rows
- 1st layer of 6 5x5 convolutional filters with RELU activation
- 2nd  maxpool layer
- 3rd dropout layer with keep probability 0.5
- 4th layer of 6 5x5 convolutional filters with RELU activation
- 5th  maxpool layer
- 6th dropout layer with keep probability 0.5
- 7th flattening layer
- 8th dense layer with 120 weights and RELU activation
- 9th dense layer with 84 weights and RELU activation
- 10th dense layer with 1 weight

See lines 81-115 in behavior-cloning.py for the corresponing code.

#### 3. Creation of the Training Set & Training Process

To capture good driving behavior, I first recorded two laps on track one using center lane driving. Here is an example image of center lane driving:

![alt text](/Users/suvo/Projects/Udacity/SDCND-Projects/CarND-Behavioral-Cloning-P4/image_center.png)

After the collection process, I had about 2x3x1600 = 9600 number of data points (factor 2 for flipping and factor 3 for using the center, left and right images and about 1600 rows in the csv file. I then preprocessed this data by using the normalization Keras lambda layer.


I finally randomly shuffled the data set and put 20% of the data into a validation set. 

I used this training data for training the model. The validation set helped determine if the model was over or under fitting. The ideal number of epochs was 10 as evidenced by slowing down of the training loss. I used an adam optimizer. Although I added code to play with the learning rate, I didn't need to use it.

---

**Final Words**

I was ecstatic when the car started driving autonomously!

It was a fun project.