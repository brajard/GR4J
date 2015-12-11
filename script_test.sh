#/bin/sh

#ESSAI=
#FNAME=''$1''
#echo $FNAME
#echo $1
awk '$2=="function:" && $3=="J(Xo)" {print $5}' $1 > Jxo.dat
awk '$7=="-K->" {print $3,$9,$10,$6}' $1  > J.dat 
sed 's/@.0/nan/g' J.dat > tmp.dat
mv tmp.dat J.dat
#echo balabl
#echo $1
matlab -nodesktop -nodisplay -r 'plot_mat ; exit'

