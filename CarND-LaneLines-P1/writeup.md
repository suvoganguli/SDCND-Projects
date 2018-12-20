## **Project 1: Finding Lane Lines on the Road** 

### Goal

The goal of this project is to find the lanes on a lane from a video using computer vision techniques.

### Technical Approach

My pipeline consisted of the following steps: 
- Convert the colored image into grayscale 
- Blur the image using a Gaussian kernel to remove high spatial frequency content 
- Create a region of interest (a triangle in this case) for identifying lanes 
- Run Hough transformation to capture straight line edges 
- Grouping the line segments based on +ve or -ve slope 
- Develop the draw_lines() function to paint the lane markings based on the above grouped lane segments 

In order to draw a single line on the left and right lanes, I modified the draw_lines() function by: 
- Computing the slope of each line segments obtained from Hough transform 
- Separating the lane segments based upon the slope (+ve or -ve) 
- Finding the minimum and maximum y-value of the line segments in each group 
- Calculating the average slope in each group 
- Extrapolating the top and bottom line segments of the left and the right lane to the bottom of the image and the top of the region of interest 


### Potential Shortcomings of Current Pipeline 

The current pipeline is not robustly finding the lanes markings which are segmented. When extrapolated from a few line  segments, the identified lane line is sometimes rapidly shifting across frames. 

Additionally, the current pipeline may not work satisfactorily under the following conditions: 

1. Traffic in the region of interest 
2. Shorter radius of turn 
3. Change in lighting condition (e.g., passing through a tunnel) 
4. Cracks on the road in the region of interest 


### Possible Improvements

Possible improvements include: 

1. Improving the edge detection parameters by experimenting with: 
   - the kernel size for the Gaussian blur (possibly blur is one direction) 
   - adjusting the lower and upper threshold for Canny edge detection 
   
2. Using alternate region of interest - experiment with polygons, instead of triangles. 

3. Adjusting the Hough transform parameters.

3. Using a temporal filter which "remembers" the lane detected in previous frames and "adjusts" so as not to rapidly shift the lane markings. 


