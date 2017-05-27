extern "C" __global__ void kernel(char *out, int *width, int *height, int *numIterations){
	unsigned int xDim = blockIdx.x * blockDim.x + threadIdx.x;
	unsigned int yDim = blockIdx.y * blockDim.y + threadIdx.y;

	//index of the output array, multiplied by 3 for R,G,B values
	int arrayIndex = 3 * (*width) * yDim + xDim*3;

	float xPoint = ((float) xDim/(*width));
	float yPoint = ((float) yDim/(*width)); 

	//for calculation of complex number
	float x = 0;
	float y = 0;

	int iterationCount = 0;
	//terminating condition x^2+y^2 < 4 or iterations >numIterations
	while(y*y+x*x<=4 && iterationCount<(*numIterations)){
		float xTemp = x*x-y*y + xPoint;
		y = 2*x*y + yPoint;
		x = xTemp;
		iterationCount++;
	}

	if(iterationCount == (*numIterations)){
		out[arrayIndex] = 0;
		out[arrayIndex+1]=0;
		out[arrayIndex+2]=0;
	}else{
		out[arrayIndex] = iterationCount;
		out[arrayIndex+1]=iterationCount;
		out[arrayIndex+2]=iterationCount;
	}
}