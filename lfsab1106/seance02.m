%%%%%%%%%%%%%%%%%%
%NOM : AMANPREET %
%PRENOM : SINGH  %
%NOMA : 86851400 %
%GROUPE : 01     %
%%%%%%%%%%%%%%%%%%

function [y,ny] = seance02(x,nx,z,nz)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%fonction qui calcule la convolution entre le signal discret x et z       %
%@pre -- prend en arguments deux VECTEURS x,z qui sont 2 signaux discret, %
%        prend 2 autres vecteurs nx,nz qui sont des listes d'entiers      %
%        succ�ssifs ou les signaux sont d�finis                           %
%@post -- renvoie un VECTEUR y qui est la convolution de x et z, renvoie  %
%         un autre VECTEUR ny qui une liste d'entier ou le signal         %
%         y est d�fini.                                                   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%check
if (length(nx)~=length(x) || length(nz)~=length(z))
    error('Les tailles des vecteurs nx et x et/ou nz et z sont diff�rentes ou sont vides');
%ok
else
y = conv(x,z) %calcul de la convolution 
ny = (min(nx)+min(nz)):1:(max(nx)+max(nz))%calcul de la largeur de 
                                           %l'interval de la convulution
                                           %en prenant la somme des min 
                                           %pour la borne de gauche et la 
                                           %somme des max pour la borne de 
                                           %droite, en incr. de un. 

figure('Name','Tout bon programme qui calcule la convolution y de x et z')
%affiche les 2 signaux et la convolution : 
subplot(3,1,1) %3 lignes, 1 colonne, 1er �l�ment : signal x
stem(nx,x); xlabel('n'); ylabel('x[n]');

subplot(3,1,2)  %3 lignes, 1 colonne, 2�me �l�ment : signal z
stem(nz,z); xlabel('n'); ylabel('z[n]');

subplot(3,1,3)  %3 lignes, 1 colonne, 3�me �l�ment : signal y
stem(ny,y,'r'); xlabel('n'); ylabel('y[n]');

end