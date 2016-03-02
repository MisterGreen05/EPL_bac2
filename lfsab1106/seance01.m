%%%%%%%%%%%%%%%%%%%%%
%PRENOM : SINGH     %
%NOM : AMANPREET    %
%NOMA : 86851400    %
%NUMERO GROUPE : 1 %
%%%%%%%%%%%%%%%%%%%%%

function [y1,y2,y3] = seance01(n,n_0)
%@PRE -- prend 2 arguments, n VECTEUR d'entiers cons�cutifs et n_0 un
%ENTIER (d�calage)
%@POST -- affiche y1,y2,y3 qui sont 3 signaux (impulsion,
%�chelon et rampe discr�te selon un d�calage n_0)

%valeurs test�s par moi meme 
%n=-10:10;
%n_0=2;

%calcul du d�calage pour chaque fonction
for i=1:length(n)
    y1(i)=impulse(n(i)-n_0);
end
for i=1:length(n)
    y2(i)=heaviside(n(i)-n_0);
end
for i=1:length(n)
    y3(i)=ramp(n(i)-n_0);
end

%affiche les 3 signaux dans 3 figures diff�rentes
figure('Name','Fonction impulsion I, d�cal� de n_0 en temps discret','NumberTitle','off')
stem(n,y1)
xlabel('N')
ylabel('I')

figure('Name','Fonction �chelon E, d�cal� de n_0 en temps discret','NumberTitle','off')
stem(n,y2)
xlabel('N')
ylabel('E')

figure('Name','Fonction rampe R, d�cal� de n0 en temps discret','NumberTitle','off')
stem(n,y3)
xlabel('N')
ylabel('R')
end

%fonction impulsion de dirac (implementation selon la definition, trivial)
function y1 = impulse(n)
    if n==0
        y1=1;
    else 
        y1=0;
    end
end
%fonction echelon (implementation selon la definition, trivial)
function y2 = heaviside(n)
    if n<0
        y2=0;
    else
        y2=1;
    end
end
%fonction rampe (implementation selon la definition, trivial)
function y3 = ramp(n)
    if n<0
        y3=0;
    else
        y3=n;
    end
end

