/************************************************************
		module RX32.h -
*************************************************************/

forward(YREAL RX3){

	YS1 = 1 - pow((1+RX3),-0.25);	
}

//===========================================================
backward(YREAL RX3){

	YJ1I1 = (0.25) * pow((1+RX3),-1.25);
}
