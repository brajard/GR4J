%%%%%%%%%%%%%%%%%%Nash


debit=DebitHC5;

%qtot1=qtot_assim(31:end);
qtot1=qtot(31:end);
somme=0;
somme2=0;
Qbar=mean(debit(:,3));
for i=1:4008
	somme=(debit(i,3)-qtot1(i))^2+somme;
	somme2=somme2+(debit(i,3)-Qbar)^2;
end
div=somme/somme2;
nash=(1-div)*100 ;
