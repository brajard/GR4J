/************************************************************
		module QD.h -
*************************************************************/

forward(YREAL Q1F){

  if (Q1F>0) YS1=Q1F;
  else YS1=0;
  
//	YS1 = Q1F>0 ? Q1F:0;
		
	
}

//===========================================================
backward(YREAL Q1F){
	
		
	if(Q1F>0){
		YJ1I1=1;
	}
	
}
 
