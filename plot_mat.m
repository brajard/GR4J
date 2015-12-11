load Jxo.dat;
load J.dat

alpha=J(:,1);
%delta=(J(:,2)-Jxo) - J(:,3);
delta=abs(J(:,4));
X=[min(alpha) max(alpha)];

figure(1)
clf
loglog(X,X.^2,'-k');
hold on
loglog(X,X,'-r');

loglog(alpha,delta,'+-b')
loglog(X,repmat(eps*Jxo,size(X)),':k');
print -dpng residu.png