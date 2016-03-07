%%%%%%%%%%%%%%%%%%%%%
% Nom : SINGH       %
% Prenom : AMANPREET%
% NOMA : 86851400   %  
% Groupe : 01       %
%%%%%%%%%%%%%%%%%%%%%

load('signal.mat');

%partie1

N=15; %periode
omega=2*pi/N; %frequence angulaire

k = -((N-1)/2):((N-1)/2); %nombre d'echantillos
n = 1:length(x); 

%calcul du signal sur une periode
for i = 1:15
    xP(i) = x(4+i);
end

%calcul des coeff de Fourier sur une periode
X=fftshift(fft(xP))/N;

%arrondies
for i=1:length(X)
    if X(i)<=1e-9
        X(i)=0;
    end
end

%calcul du module et de la phase
magnitude = abs(X);
phase = unwrap(angle(X));

%plot des deux
subplot(2,1,1)
stem(k,magnitude)
title('Module des coefficients de la serie de Fourier en fonction d''echantillons');
xlabel('k'); ylabel('|X[k]|');

subplot(2,1,2)
stem(k,phase)
title('Argument des coefficients de la serie de Fourier en fonction d''echantillons');
xlabel('k'); ylabel('arg(X[k])');

%partie2

%je n'arrivais pas a l'implementer avec des boucles donc j ai 
%calculer a la main il n'y avait que 7 coeff de Fourier non nul
%ce qui donne les 4 composantes suivantes
%j'ai juste calculer les X(k) et puis j ai utilise la formule
%sum k=0 a N-1 de X(K)e(jKomega0n) et X[K]=X*[-K] pour un signal
%reel
%c'est mieux ca que rien ..

display('x[n] = 2 +2(4.5cos(2*pi*n/15) + 3cos(2*pi*n/5) +1.25(8*pi*n/15 +2*pi/3))');

%composante dominante = celles dont le module est le plus important

c1 = 4.5*cos(2*pi*n/15);%comp dominante
c2 = 3*cos(2*pi*n/5);%2 eme comp dominante
c12 = [c1;c2]';%pour plot sur un meme graphe

figure
%plot
subplot(3,1,1)
stem(n,x);
title('Signal original en fonction de n');
xlabel('n'); ylabel('x');
subplot(3,1,2)
stem(n,c1);
title('Composante dominante du signal');
xlabel('n'); ylabel('4.5*cos(2*pi*n/15)');
subplot(3,1,3)
stem(n,c12);
title('Les deux composantes dominantes du signal');
xlabel('n'); ylabel('Les 2 composantes dominantes');
legend('4.5*cos(2*pi*n/15)','3*cos(2*pi*n/5)')
