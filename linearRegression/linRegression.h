#ifndef MY_HEADER_H
#define MY_HEADER_H

//declaring functions


/*Determines cost and adjusts
*weights and bias
*/
float batch_gradient_descent();

/*runs linear regression through iterations.
*Determines weights and biases and cost in
*each iteration.
*Returns array with cost values.
*/
float* regression();

/*predicts output given input values*/
float predict();

#endif
