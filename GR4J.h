
///////////////////////////////////////////////////////////////////////////////
// define, globales, fonctions perso (obligatoire et autres) ...
///////////////////////////////////////////////////////////////////////////////


// DES PROTOTYPAGES NECESSAIRES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// Les fonctions propres à l'appli :===========================================
//   les OBLIGATOIRES
//_____________________________________________________________________________
YREAL temp[40];
YREAL tempd[40];
void xdisplay();

void appli_start (int argc, char *argv[])
{			// permet si besoin de prendre la main des le debut de l'appli
			printf("\t*************************************************************\n");
			printf("\t**********  Assimiliation de donnees:modele HBV *************\n");
			printf("\t*************************************************************\n");
			int ii;
			for(ii=0;ii<40;ii++){
				temp[ii]=0;
			}
			
			

	
}
//_____________________________________________________________________________
void before_it (int Yit)
{			// permet d'intervenir si besoin avant une iteration
}
//_____________________________________________________________________________
void cost_function (int pdt)
{			// fonction de cout (si les standards ne conviennent pas)
}
//_____________________________________________________________________________
void adjust_target ()
{			// fonction d'ajustement (si la standard ne convient pas)
}
//_____________________________________________________________________________
void after_it (int nit)
{			// permet d'intervenir si besoin apres une iteration
}
//_____________________________________________________________________________
void forward_before (int ctrp)
{			// permet d'intervenir si besoin avant le forward
}
//_____________________________________________________________________________
void forward_after (int ctrp)
{			// permet d'intervenir si besoin apres le forward
//pb: affichage des valeurs: ca affiche toujours les memes valeurs (initiales)
}
//_____________________________________________________________________________
void backward_before (int ctrp)
{			// permet d'intervenir si besoin avant le backward
}
//_____________________________________________________________________________
void backward_after (int ctrp)
{			// permet d'intervenir si besoin apres le backward
}
//_____________________________________________________________________________
short select_io(int indic, char *nmmod, int sortie, int iaxe, int jaxe, int kaxe, int pdt, YREAL *val)
{			// Pour faire des selections sur les fonctions d'entrees sorties de Yao ou autre en generale.
			// Doit retourner 1 si l'element dont les caracteristiques sont passes en parametre doit
			// etre retenu, pris, selectionne ; et 0 sinon
			// indic permet de savoir de quelle instance provient l'appel :
			// =YIO_LOADSTATE	 => appel via loadstate
			// =YIO_SAVESTATE	 => appel via savestate
			// =YIO_LOADOBS	   => appel via loadobs
			// =YIO_OUTOOBS	   => appel via outoobs
			// =YIO_LISTOBS	   => appel via listobs
			return(1);
}
//-----------------
void	xdisplay ()
{
	//int i=0;
	printf("setstate X1  % -16.8e \n", YS1_X1(0));
	printf("setstate X2  % -16.8e \n", YS1_X2(0));
	printf("setstate X3  % -16.8e \n", YS1_X3(0));
	printf("setstate X4  % -16.8e \n", YS1_X4(0));
	printf("S----------- % -16.8e \n", YS1_MS3(0,0));
	printf("R----------- % -16.8e \n", YS1_R2(0,29));
	ofstream fichier("initSw", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
	if(fichier){
		fichier << "init  "<<YS1_R2(0,29)<<"  "<<YS1_R2(0,28)<<"  "<<YS1_R2(0,27)<<"  "<<YS1_R2(0,26)<<"  "<<YS1_R2(0,25)<<"  "<<YS1_R2(0,24)<<"  "<<YS1_R2(0,23)<<"  "<<YS1_R2(0,22)<<endl;
	}else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
 
       /** ofstream fichier("SW", ios::app);
	ofstream fichier_2("SWD", ios::app);
	printf("*************** ------------------ >s=% d \n", YTemps);
	for(i=0;i<299;i++){	
		fichier << YS_SX1(1,1,i) <<endl;
		fichier_2<<YG_SX1(1,1,i) <<endl;	
	}**/
}


void load_in(char *file){



}

void init(int argc, char *argv[]){

	YS1_R2 (0,29) = atof(argv[1]);
	YS1_R2 (0,28) = atof(argv[2]);
	YS1_R2 (0,27) = atof(argv[3]);
	YS1_R2 (0,26) = atof(argv[4]);
	YS1_R2 (0,25) = atof(argv[5]);
	YS1_R2 (0,24) = atof(argv[6]);
	YS1_R2 (0,23) = atof(argv[7]);
	YS1_R2 (0,22) = atof(argv[8]);
 
}

//_____________________________________________________________________________
// LES AUTRES (appelable depuis n'importe quel module et par l'interpréteur
//_____________________________________________________________________________
/*void xprint_xinf()
	{
	  int j;
	  for (j=0;j<YNBMODUL;j++)
	    {
	      if (GY_itarget[j]>-1)
	        {
	          printf("Module %s(%d) : min=%f, max=%f\n",YTabMod[j].Name,GY_itarget[j],Y3xinf[GY_itarget[j]*YTabMod[j].axi],Y3xsup[GY_itarget[j]*YTabMod[j].axi]);
	        }
	    }
	 
	}
*/
