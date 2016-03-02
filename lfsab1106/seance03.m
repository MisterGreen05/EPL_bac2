%%%%%%%%%%%%%%%%%%%%
%nom : Singh       %
%prenom : Amanpreet%
%NOMA : 86851400   %
%nr gr. : 01       %
%%%%%%%%%%%%%%%%%%%%

function [ioc itc iod itd] = seance03(tfin)
%calcule et affiche la reponse impulsionnelle de deux systemes ainsi que 
%l'évolution de leurs variables internes sur une duree de tfin

%q1 : evolution var d'état du sys originale continue
%t1 : interval de simulation original continu, en fonction de tfin 
%ioc : réponse impulsionnelle originale continue
%z1 : evolution var d'état du sys transformée continue
%tT1 : interval de simulation transformé, en fonction de tfin
%itc : réponse impulsionnelle transformée continue

%q2 : evolution var d'état du sys originale discret
%t2 : interval de simulation original discret, en fonction de tfin 
%iod : réponse impulsionnelle originale discret
%z1 : evolution var d'état du sys transformée discret
%tT2 : interval de simulation transformé discret, en fonction de tfin
%itd : réponse impulsionnelle transformée discret

a = [-2 0 ; 1 -1];
b = [1 ; 1];
c = [0 2];
d = [1];
T = [2 1; 1 -1];
sys = ss(a,b,c,d); %state-space model, systeme LTI original
sysT = ss2ss(sys,T); %systeme LTI transformé
[ioc,t1,q1] = impulse(sys,tfin); 
[itc,tT1,z1] = impulse(sysT,tfin);

%meme raisonnement pour le systeme discret

a2 = [-0.1 0.4; 0.4 -0.1]; 
b2 = [2;4];
c2 = [0.5 0.5];
d2 = [2];
T2 = [-0.5, 0.5;0.5 0.5];
sys2 = ss(a2,b2,c2,d2,-1);
sysT2 = ss2ss(sys2,T2);
[iod, t2, q2] = impulse(sys2,tfin);
[itd, tT2, z2] = impulse(sysT2,tfin);


%%%%%%%%%%%%%%%%%%%%%%%%%
%plot du système continu%
%%%%%%%%%%%%%%%%%%%%%%%%%

figure('name','Système continue');
subplot(2,1,1)
plot(t1, ioc);
title('Réponse impulsionnelle du système original');
xlabel('Temps'); ylabel('Amplitude');

subplot(2,1,2)
plot(tT1, itc);
title('Réponse impulsionnelle du système transformé');
xlabel('Temps'); ylabel('Amplitude');

figure('name','Système continue');
subplot(2,1,1)
plot(t1,q1); legend('q1','q2')
title('Evolution des variables d''états du système original');
xlabel('Temps'); ylabel('q');

subplot(2,1,2)
plot(tT1,z1); legend('z1','z2')
title('Evolution des variables d''états du système transformé');
xlabel('Temps'); ylabel('z');

%%%%%%%%%%%%%%%%%%%%%%%%%
%plot du système discret%
%%%%%%%%%%%%%%%%%%%%%%%%%
figure('name','Système discret');
subplot(2,1,1)
stem(t2, iod);
title('Réponse impulsionnelle du système original');
xlabel('n'); ylabel('Amplitude');

subplot(2,1,2)
stem(tT2, itd);
title('Réponse impulsionnelle du système transformé');
xlabel('n'); ylabel('Amplitude');

figure('name','Système discret');
subplot(2,1,1)
stem(t2,q2); legend('q1','q2')
title('Evolution des variables d''états du système original');
xlabel('n'); ylabel('q');

subplot(2,1,2)
stem(tT2,z2);legend('z1','z2')
title('Evolution des variables d''états du système transformé');
xlabel('n'); ylabel('z');

end


