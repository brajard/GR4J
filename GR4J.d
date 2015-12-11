#==========================================================
# 	       fichier de DESCRIPTION HBV.d
#
#        RESPECTER L'ORDRE DE DECLARATION DES DIRECTIVES
#==========================================================
#DEFVAL pour definir des trucs ----------------------DEFVAL

defval NT 15109                                                      //Nombre de pas de temps
########defval NT 2386//Nombre de pas de temps
#####defval NT 87648 //Nombre de pas de temps
defval SIZE   40
#NAME ---------------------------------------------HAT_NAME
hat_name "GR4J.h"

#OPTION ---------------------------------------------OPTION
option  O_GRADTEST
option  O_M1QN3
#option O_REAL float
option  O_VARINCR
###option  O_cadna 

#TRAJECTOIRES ------(en secondes)----------------------TRAJ
#traj  nom  type upt  offt dt stept
traj  Tpar   M   0         1
traj  Tm     M   30         NT			 

 
#ESPACES ---------------------------------------------SPACE
#space  nom  type  SZX SZY  Traj
space  Sm     M   1       Tm
space  Spar   M   1       Tpar

#MODULES -------------------------------------------MODULES
## x1=capacite du reservoir de production (mm)
## x2=coefficient d'echanges souterrains (mm)
## x3=capacite a un jour du reservoir de routage (mm)
## x4=temps de base de l'hydrogramme unitaire HU1 (j)
//Paramètres
modul X1   space Spar noward output 1  	  target
modul X2   space Spar noward output 1  	  target
modul X3   space Spar noward output 1  	  target
modul X4   space Spar noward output 1    target
 
//EntréesP (mm) la hauteur du pluie 

##P (mm)=la hauteur du pluie et par 
## E (mm)=l’évapotranspiration potentielle (ETP)
modul P  space Sm noward output 1 tempo
modul E  space Sm noward output 1 tempo

//Variables d'etat


modul INTERC    space Sm input 2 output 2 tempo
modul SX1      space Sm input 2 output 1 tempo  
modul PNX1     space Sm input 2 output 1 tempo
modul ENX1     space Sm input 2 output 1 tempo
modul tanhPS   space Sm input 1 output 1 tempo
modul tanhES   space Sm input 1 output 1 tempo
//modul PS       space Sm input 6 output 2 tempo

modul PS1       space Sm input 5 output 2 tempo
modul PS2       space Sm input 3 output 2 tempo
modul PS3       space Sm input 5 output 2 tempo
//modul S        space Sm input 4 output 2 tempo

modul MS1        space Sm input 3 output 1 tempo
modul MS21       space Sm input 1 output 1 tempo
modul MS23       space Sm input 2 output 1 tempo
modul MS24       space Sm input 2 output 1 tempo
modul MS3        space Sm input 2 output 1 tempo   

modul PR       space Sm input 3 output 1 tempo 

modul Q9       space Sm input 31 output 1 tempo   
modul Q1       space Sm input 31 output 1 tempo	   


modul F        space Sm input 3 output 1 tempo
modul QR       space Sm input 2 output 1 tempo

modul RQ9F     space Sm input 3 output 1 tempo
modul R1       space Sm input 1 output 1 tempo

modul R2       space Sm input 2 output 1 tempo  

modul RX3     space Sm input 2 output 1 tempo
modul RX32    space Sm input 1 output 1 tempo

modul Q1QF     space Sm input 2 output 1 tempo
modul QD       space Sm input 1 output 1 tempo
modul QS       space Sm input 2 output 1 tempo  cout




//CONNECTIONS ----------------------------------------CTIN-M


ctin INTERC  1  from P    1     i     t
ctin INTERC  2  from E    1     i     t

ctin SX1    1  from MS3   1   i       t-1
ctin SX1    2  from X1    1   i    

ctin PNX1   1  from INTERC   1   i    t
ctin PNX1   2  from X1   1   i

ctin ENX1   1  from INTERC   2   i    t
ctin ENX1   2  from X1   1   i

ctin tanhPS 1  from PNX1 1   i    t
ctin tanhES 1  from ENX1 1   i    t

ctin PS1   1   from MS3         1   i   t-1
ctin PS1   2   from SX1         1   i   t
ctin PS1   3   from tanhPS      1   i   t
ctin PS1   4   from tanhES      1   i   t
ctin PS1   5   from X1          1   i   

ctin PS2   1   from SX1         1   i   t
ctin PS2   2   from tanhPS      1   i   t
ctin PS2   3   from tanhES      1   i   t


ctin PS3   1   from PS1         1   i   t
ctin PS3   2   from PS1         2   i   t
ctin PS3   3   from PS2         1   i   t  
ctin PS3   4   from PS2         2   i   t
ctin PS3   5   from INTERC      1   i    t


ctin MS1     1  from MS3          1   i    t-1
ctin MS1     2  from PS3          1   i    t
ctin MS1     3  from PS3          2   i    t

ctin MS23    1  from MS1          1   i    t
ctin MS23    2  from X1          1   i


ctin MS21    1  from MS23         1   i    t

ctin MS24    1  from MS1          1   i    t
ctin MS24    2  from MS21         1   i    t

ctin MS3     1  from MS1          1   i    t
ctin MS3     2  from MS24         1   i    t

ctin PR     1  from INTERC        1   i    t
ctin PR     2  from PS3           1   i    t
ctin PR     3  from MS24          1   i    t

//ce n'est pas la manière la plus optimale mais bon comme on a un petit modèle on peut se le peremettre

ctin Q9     1   from PR            1   i    t
ctin Q9     2   from PR            1   i    t-1
ctin Q9     3   from PR            1   i    t-2
ctin Q9     4   from PR            1   i    t-3
ctin Q9     5   from PR            1   i    t-4
ctin Q9     6   from PR            1   i    t-5
ctin Q9     7   from PR            1   i    t-6
ctin Q9     8   from PR            1   i    t-7
ctin Q9     9   from PR            1   i    t-8
ctin Q9     10  from PR            1   i    t-9
ctin Q9     11  from PR            1   i    t-10
ctin Q9     12  from PR            1   i    t-11
ctin Q9     13  from PR            1   i    t-12
ctin Q9     14  from PR            1   i    t-13
ctin Q9     15  from PR            1   i    t-14
ctin Q9     16  from PR            1   i    t-15
ctin Q9     17  from PR            1   i    t-16
ctin Q9     18  from PR            1   i    t-17
ctin Q9     19  from PR            1   i    t-18
ctin Q9     20  from PR            1   i    t-19
ctin Q9     21  from PR            1   i    t-20
ctin Q9     22  from PR            1   i    t-21
ctin Q9     23  from PR            1   i    t-22
ctin Q9     24  from PR            1   i    t-23
ctin Q9     25  from PR            1   i    t-24
ctin Q9     26  from PR            1   i    t-25
ctin Q9     27  from PR            1   i    t-26
ctin Q9     28  from PR            1   i    t-27
ctin Q9     29  from PR            1   i    t-28
ctin Q9     30  from PR            1   i    t-29
ctin Q9     31  from X4            1   i 

ctin Q1     1   from PR            1   i    t
ctin Q1     2   from PR            1   i    t-1
ctin Q1     3   from PR            1   i    t-2
ctin Q1     4   from PR            1   i    t-3
ctin Q1     5   from PR            1   i    t-4
ctin Q1     6   from PR            1   i    t-5
ctin Q1     7   from PR            1   i    t-6
ctin Q1     8   from PR            1   i    t-7
ctin Q1     9   from PR            1   i    t-8
ctin Q1     10  from PR            1   i    t-9
ctin Q1     11  from PR            1   i    t-10
ctin Q1     12  from PR            1   i    t-11
ctin Q1     13  from PR            1   i    t-12
ctin Q1     14  from PR            1   i    t-13
ctin Q1     15  from PR            1   i    t-14
ctin Q1     16  from PR            1   i    t-15
ctin Q1     17  from PR            1   i    t-16
ctin Q1     18  from PR            1   i    t-17
ctin Q1     19  from PR            1   i    t-18
ctin Q1     20  from PR            1   i    t-19
ctin Q1     21  from PR            1   i    t-20
ctin Q1     22  from PR            1   i    t-21
ctin Q1     23  from PR            1   i    t-22
ctin Q1     24  from PR            1   i    t-23
ctin Q1     25  from PR            1   i    t-24
ctin Q1     26  from PR            1   i    t-25
ctin Q1     27  from PR            1   i    t-26
ctin Q1     28  from PR            1   i    t-27
ctin Q1     29  from PR            1   i    t-28
ctin Q1     30  from PR            1   i    t-29
ctin Q1     31  from X4            1   i 

ctin F      1  from R1             1   i    t-1
ctin F      2  from X2             1   i  
ctin F      3  from X3             1   i

ctin RQ9F     1  from R2             1   i    t-1
ctin RQ9F     2  from Q9             1   i    t
ctin RQ9F     3  from F              1   i    t

ctin R1       1  from RQ9F           1   i    t


ctin RX3    1  from R1             1   i    t
ctin RX3    2  from X3             1   i    

ctin RX32   1  from RX3            1   i    t

ctin QR     1  from R1             1   i    t
ctin QR     2  from RX32           1   i    t

ctin R2     1  from R1            1   i    t
ctin R2     2  from QR            1   i    t



ctin Q1QF     1  from Q1            1   i    t
ctin Q1QF     2  from F             1   i    t 

ctin QD       1  from Q1QF          1   i    t 

ctin QS     1  from QR            1   i    t
ctin QS     2  from QD            1   i    t
 

//ORDER -----------------------------------------------ORDER
order modinspace Sm
      order YA1  
	INTERC
	SX1
	PNX1
	ENX1
	tanhPS
	tanhES
	PS1
	PS2
	PS3
	MS1
	MS23	
	MS21
	MS24
	MS3
	PR
	Q9
	Q1
	F
	RQ9F
	R1
	RX3
	RX32
	QR
	R2
	Q1QF
	QD
	QS
      forder
forder
//-----
order spaceintraj Tm
      Sm
forder

//USER FUNCTIONS ---------------------------------------UFCT
insert_fct     xdisplay
insert_fct arg init

//FIN ================================================== END
