#==========================================================
#            fichier de D'INSTRUCTIONS HBV.i
#nb PAS DE TAB, un retour chariot en fin de fichier
#==========================================================
echo on

#==========================================================
# 1) INITIALISATION DU MODELE

setstate X1  131.3
setstate X2  -18
setstate X3  407.6
setstate X4  1.1 

#################################################################################


loadstate P 1 i 0 A 1   /usr/home/nylod/Desktop/GR4J/donneesBenin/plui3 D
loadstate E 1 i 0 A 1  /usr/home/nylod/Desktop/GR4J/donneesBenin/ETP3 D

######################################################################################
 
set_modeltime   0
FORWARD
load_inst /usr/home/nylod/Desktop/GR4J/script/sensiblite.i
savestate QS    1 i  1% A 0  ./result/qtot.dat	
load_inst ./script/save.i

loadobs QS 1 i 0 A 1  /usr/home/nylod/Desktop/GR4J/donneesBenin/debit3 D


######outoobs QS 1 2386



setstate X1  131.3
setstate X2  -18
setstate X3  407.6
setstate X4  1.1 



####load_inst /usr/home/nylod/Desktop/GR4J/script/sensiblite.i
goto fin

#preparation de l'assimilation 
cost lms 0.5

#instruction li�es � m1qn3

print_cost ON
setm_impres   5
setm_io       6
setm_mode     1
set_nbiter  200
setm_nsim   200
setm_dxmin    1.0e-20
setm_epsg     1.0e-20
setm_ddf1     100 


setstate X1  131.3
setstate X2  -18
setstate X3  407.6
setstate X4  1.1 


xdisplay
runm									
xdisplay


savestate X1  1 i  0  A 0  /usr/home/nylod/Desktop/GR4J/result/toto1
savestate X2  1 i  0 A 0  /usr/home/nylod/Desktop/GR4J/result/toto2
savestate X3  1 i  0 A 0  /usr/home/nylod/Desktop/GR4J/result/toto3
savestate X4  1 i  0  A 0  /usr/home/nylod/Desktop/GR4J/result/toto4




# ====> sauvegarde de la trajectoire calcul�e (pour voir)

fin
