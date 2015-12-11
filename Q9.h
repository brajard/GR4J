/************************************************************
		module Q9.h -
*************************************************************/

forward(YREAL PR,YREAL PR1, YREAL PR2,YREAL PR3,YREAL PR4,YREAL PR5,YREAL PR6,YREAL PR7,YREAL PR8,YREAL PR9,YREAL PR10,YREAL PR11,YREAL PR12,YREAL PR13,YREAL PR14,YREAL PR15,YREAL PR16,YREAL PR17,YREAL PR18,YREAL PR19,YREAL PR20,YREAL PR21,YREAL PR22,YREAL PR23,YREAL PR24,YREAL PR25,YREAL PR26,YREAL PR27,YREAL PR28,YREAL PR29, YREAL X4){

	int l = floor(X4)+1;
	int i=0;int k1=0;int h=0;	

	YREAL somme=0;
	YREAL tempk[SIZE];
	
	int tab[32];
	
	for(i = 0; i<33;i++){
		if(i<l)
			tab[i]=1;
		else
			tab[i]=0;
	}
	
	//printf("*************** ------------------ >s=% -16.8e \n", X4);
	
	tempk[0] = 0;            //SH1
	for(h =1; h<SIZE;h++){   //  Size est la capacité max du tableau 40 par exemple
		if(h<X4){
			// hy tempk[h] = pow((h/X4),2.25);
                          tempk[h] = pow((h/X4),2.5);
		}else if(h>=X4){
			tempk[h] = 1;			
		}
	}	

	

	for(k1=SIZE-1;k1>0;k1--){   //UH1 = SH1(j)-SH1(j-1)  on peut ignorer le 7 car dans mon exemple X4 = 6.8
		//printf("SH1(%d)-SH1(%d) : >s=% -16.8e - % -16.8e  =  ",k1,k1-1, tempk[k1],tempk[k1-1]);
		tempk[k1] -= tempk[k1-1];
		//printf("*************** ------------------ >s=% -16.8e \n", tempk[k1])	;
	}
	//if(X4>0) tab[0]=1;//la valeur de tab[0] = -1082130432 bug de linux ou Yao aucune idée (rm tab[0] et le max des int)peut etre si on converti en un YREAL
	
	//printf("%d * % -16.8e * % -16.8e + %d * % -16.8e * % -16.8e +%d * % -16.8e * % -16.8e +%d * % -16.8e * % -16.8e +%d * % -16.8e * % -16.8e +%d * % -16.8e * % -16.8e +%d * % -16.8e * % -16.8e   =  \n",tab[0],tempk[1],PR,tab[1],tempk[2],PR1,tab[2],tempk[3],PR2,tab[3],tempk[4],PR3,tab[4],tempk[5],PR4,tab[5],tempk[6],PR5,tab[6],tempk[7],PR6);

	somme = tab[0]*tempk[1]*PR+tab[1]*tempk[2]*PR1+tab[2]*tempk[3]*PR2+tab[3]*tempk[4]*PR3+tab[4]*tempk[5]*PR4+tab[5]*tempk[6]*PR5+tab[6]*tempk[7]*PR6+tab[7]*tempk[8]*PR7+tab[8]*tempk[9]*PR8+tab[9]*tempk[10]*PR9+tab[10]*tempk[11]*PR10+tab[11]*tempk[12]*PR11+tab[12]*tempk[13]*PR12+tab[13]*tempk[14]*PR13+tab[14]*tempk[15]*PR14+tab[15]*tempk[16]*PR15+tab[16]*tempk[17]*PR16+tab[17]*tempk[18]*PR17+tab[18]*tempk[19]*PR18+tab[19]*tempk[20]*PR19+tab[20]*tempk[21]*PR20+tab[21]*tempk[22]*PR21+tab[22]*tempk[23]*PR22+tab[23]*tempk[24]*PR23+tab[24]*tempk[25]*PR24+tab[25]*tempk[26]*PR25+tab[26]*tempk[27]*PR26+tab[27]*tempk[28]*PR27+tab[28]*tempk[29]*PR28+tab[29]*tempk[30]*PR29;
	//printf("% -16.8e \n",somme);
	
	YS1 = 0.9* somme;	
	
}

//===========================================================
backward(YREAL PR,YREAL PR1, YREAL PR2,YREAL PR3,YREAL PR4,YREAL PR5,YREAL PR6,YREAL PR7,YREAL PR8,YREAL PR9,YREAL PR10,YREAL PR11,YREAL PR12,YREAL PR13,YREAL PR14,YREAL PR15,YREAL PR16,YREAL PR17,YREAL PR18,YREAL PR19,YREAL PR20,YREAL PR21,YREAL PR22,YREAL PR23,YREAL PR24,YREAL PR25,YREAL PR26,YREAL PR27,YREAL PR28,YREAL PR29, YREAL X4){
	
	int l = floor(X4)+1;
	int h=0,i=0;int k1;
	YREAL tempk[SIZE];
	YREAL tempkd[SIZE];

	int tab[32];
	for(i = 0; i<32;i++){
		if(i<l)
			tab[i]=1;
		else
			tab[i]=0;
	}

	tempkd[0] = 0;    //SH1
	for(h =1; h<SIZE;h++){
		if(h<X4){
			//tempkd[h] = - pow(h,1.25) * (1.25/(pow(X4,2.25)));//pow((h/X4),2.5);
                       tempkd[h]=-2.5*(h/(X4*X4))*pow(h/X4,1.5);
		}else if(h>=X4){
			tempkd[h] = 0;			
		}
	}	

	tempk[0] = 0;            //SH1
	for(h =1; h<SIZE-1;h++){   //  Size est la capacité max du tableau 40 par exemple
		if(h<X4){
			tempk[h] = pow((h/X4),2.5);
		}else if(h>=X4){
			tempk[h] = 1;			
		}
	}
	
	for(k1=SIZE-1;k1>0;k1--){   //UH1 = SH1(j)-SH1(j-1)  on peut ignorer le 7 car dans mon exemple X4 = 6.8
		//printf("SH1(%d)-SH1(%d) : >s=% -16.8e - % -16.8e  =  ",k1,k1-1, tempk[k1],tempk[k1-1]);
		tempk[k1] -= tempk[k1-1];
		//printf("*************** ------------------ >s=% -16.8e \n", tempk[k1])	;
	}

	for(k1=SIZE-1;k1>0;k1--){   //UH1 = SH1(j)-SH1(j-1)  on peut ignorer le 7 car dans mon exemple X4 = 6.8
		//printf("SH1(%d)-SH1(%d) : >s=% -16.8e - % -16.8e  =  ",k1,k1-1, tempk[k1],tempk[k1-1]);
		tempkd[k1] -= tempkd[k1-1];
		//printf("*************** ------------------ >s=% -16.8e \n", tempk[k1])	;
	}

	
		
	YJ1I1= 0.9 *tab[0]*tempk[1];
	YJ1I2= 0.9 *tab[1]*tempk[2];
	YJ1I3= 0.9 *tab[2]*tempk[3];
	YJ1I4= 0.9 *tab[3]*tempk[4];
	YJ1I5= 0.9 *tab[4]*tempk[5];
	YJ1I6= 0.9 *tab[5]*tempk[6] ;
	YJ1I7= 0.9 *tab[6]*tempk[7];
	YJ1I8= 0.9 *tab[7]*tempk[8];
	YJ1I9= 0.9 *tab[8]*tempk[9];
	YJ1I10= 0.9 *tab[9]*tempk[10];
	YJ1I11= 0.9 *tab[10]*tempk[11];
	YJ1I12= 0.9 *tab[11]*tempk[12];
	YJ1I13= 0.9 *tab[12]*tempk[13];
	YJ1I14= 0.9 *tab[13]*tempk[14];
	YJ1I15= 0.9 *tab[14]*tempk[15];
	YJ1I16= 0.9 *tab[15]*tempk[16];
	YJ1I17= 0.9 *tab[16]*tempk[17];
	YJ1I18= 0.9 *tab[17]*tempk[18];
	YJ1I19= 0.9 *tab[18]*tempk[19];
	YJ1I20= 0.9 *tab[19]*tempk[20];
	YJ1I21= 0.9 *tab[20]*tempk[21] ;
	YJ1I22= 0.9 *tab[21]*tempk[22];
	YJ1I23= 0.9 *tab[22]*tempk[23];
	YJ1I24= 0.9 *tab[22]*tempk[24];
	YJ1I25= 0.9 *tab[24]*tempk[25];
	YJ1I26= 0.9 *tab[25]*tempk[26];
	YJ1I27= 0.9 *tab[26]*tempk[27];
	YJ1I28= 0.9 *tab[27]*tempk[28];
	YJ1I29= 0.9 *tab[28]*tempk[29];
	YJ1I30= 0.9 *tab[29]*tempk[30];

	YJ1I31= 0.9 *(tab[0]*tempkd[1]*PR+tab[1]*tempkd[2]*PR1+tab[2]*tempkd[3]*PR2+tab[3]*tempkd[4]*PR3+tab[4]*tempkd[5]*PR4+tab[5]*tempkd[6]*PR5+tab[6]*tempkd[7]*PR6+tab[7]*tempkd[8]*PR7+tab[8]*tempkd[9]*PR8+tab[9]*tempkd[10]*PR9+tab[10]*tempkd[11]*PR10+tab[11]*tempkd[12]*PR11+tab[12]*tempkd[13]*PR12+tab[13]*tempkd[14]*PR13+tab[14]*tempkd[15]*PR14+tab[15]*tempkd[16]*PR15+tab[16]*tempkd[17]*PR16+tab[17]*tempkd[18]*PR17+tab[18]*tempkd[19]*PR18+tab[19]*tempkd[20]*PR19+tab[20]*tempkd[21]*PR20+tab[21]*tempkd[22]*PR21+tab[22]*tempkd[23]*PR22+tab[23]*tempkd[24]*PR23+tab[24]*tempkd[25]*PR24+tab[25]*tempkd[26]*PR25+tab[26]*tempkd[27]*PR26+tab[27]*tempkd[28]*PR27+tab[28]*tempkd[29]*PR28+tab[29]*tempkd[30]*PR29);
	
}
 
