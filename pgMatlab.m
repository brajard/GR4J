for i=1:87647
	if (P(i)>E(i))
		PN(i) = P(i)-E(i);
		EN(i)=0;
	else
		PN(i)=0;
		EN(i)= E(i)-P(i);
	end
end

S(1) =0;

for i=2:87647

	if(PN(i)~=0)
		PS(i) = (280* (1-  (S(i-1)/280)^2)*   tanh(PN(i)/280)  )   / (     1+(      (S(i-1)/280) * tanh (PN(i)/280)      )       );
		ES(i)=0;
	else
		PS(i) =0;
		ES(i) = ( S(i-1) * (2- (S(i-1)/280))*tanh(EN(i)/280)) /   (1 + (1-(S(i-1)/280)) * tanh(EN(i)/280));
	end

	S1(i)=S(i-1) - ES(i) + PS(i);

	PERCM(i) = S1(i)*(1-(1+((4/9)*(S1(i)/280))^4)^(-1/4));

	S(i) = S1(i) - PERCM(i);

end



PERCM = S1(i)*(1-(1+((4/9)*(S1(i)/280))^4)^(-1/4))

QRM = R1.*(1-(1+((R1./380)).^4).^(-1/4))

for i=1:


