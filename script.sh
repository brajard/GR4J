
for ((i=1 ; i<2000 ; i++))
do	
	echo $i
	sed -e 's/defval NT 54/defval NT 48/g' GR4J.d > GR4J.d.tmp && mv -f GR4J.d.tmp GR4J.d
	YaoI GR4J
	sed -e 's/pe'$(($i*1-1))'/pe'$(($i*1))'/g' GR4J.i > GR4J.i.tmp && mv -f GR4J.i.tmp GR4J.i
	
	
	sed -e 's/e'$(($i*1-1))'/e'$(($i*1))'/g' GR4J.i > GR4J.i.tmp && mv -f GR4J.i.tmp GR4J.i
	

	sed -e 's/debit'$(($i*1-1))'/debit'$(($i*1))'/g' GR4J.i > GR4J.i.tmp && mv -f GR4J.i.tmp GR4J.i
	sed -e 's/\.\/result\/qtot'$(($i*1-1))'.dat/\.\/result\/qtot'$(($i*1))'.dat/' GR4J.i >GR4J.i.tmp && mv -f GR4J.i.tmp GR4J.i
	sed -e "s/^init.*/init  74.3268   74.3268   74.3268   74.3268   74.3268   74.3268   74.3268  74.3268 /" GR4J.i > GR4J.i.tmp && mv -f GR4J.i.tmp GR4J.i
	./GR4J
	
	read init < initSw
	echo "Initialisation avec $init"	
	
	sed -e "s/^init.*/$init/" GR4J.i >GR4J.i.tmp && mv -f GR4J.i.tmp GR4J.i
	
	sed -e 's/defval NT 48/defval NT 54/g' GR4J.d > GR4J.d.tmp && mv -f GR4J.d.tmp GR4J.d	

	YaoI GR4J

	

	./GR4J
done
