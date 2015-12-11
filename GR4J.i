#==========================================================
#            fichier de D'INSTRUCTIONS GR4J.i
#nb PAS DE TAB, un retour chariot en fin de fichier
#==========================================================
echo on

#==========================================================
# 1) INITIALISATION DU MODELE


setstate X1  205.9
setstate X2  -23.89
setstate X3  256.4
setstate X4  3.28

#####loadstate P 1 i 0 A 1   /usr/home/nylod/Desktop/GR4J1/donneesCimagref/peHoraireCalage D
#####loadstate E 1 i 0 A 1   /usr/home/nylod/Desktop/GR4J1/donneesCimagref/etpmHoraireCalage D

loadstate P 1 i 0 A 1   ./donneesBenin/PluieHV5 D
loadstate E 1 i 0 A 1  ./donneesBenin/ETPHV5 D

#load_inst ./script/sensiblite.i

set_modeltime   0
FORWARD

savestate QS    1 i  1% A 0  ./result/qtot.dat	
load_inst  ./script/save.i

#####loadobs   QS 1 i 0 A 1 ./donneesCimagref/debitHoraire D
loadobs QS 1 i 0 A 1  ./donneesBenin/DebitHV5 D

#houda
#outoobs QS 1 43854

#setstate X1  150
load_inst ./script/sensiblite.i

#preparation de l'assimilation 
cost lms 0.5

#instruction li�es � m1qn3


setstate X1  205.9
setstate X2  -23.89
setstate X3  256.4
setstate X4  3.28

#print_cost ON

setm_impres   5
setm_io       6
setm_mode     1
set_nbiter  200
setm_nsim   200
setm_dxmin    1.0e-20
setm_epsg     1.0e-20
setm_ddf1     100

#load_inst ./script/borne_Inf_Sup.i

setstate X1  205.9
setstate X2  -23.89
setstate X3  256.4
setstate X4  3.28

xdisplay
runm
xdisplay

# ====> sauvegarde de la trajectoire calcul�e (pour voir)

savestate X1  1 i  0  A 0  ./result/toto1
savestate X2  1 i  0 A 0  ./result/toto2
savestate X3  1 i  0 A 0  ./result/toto3
savestate X4  1 i  0  A 0  ./result/toto4

# ====> sauvegarde de la trajectoire calcul�e (pour voir)
savestate QS    1 i  1% A 0  ./result/qtot_assim.dat	
savestate P     1 i  1% A 3  ./result/pluie.dat	

