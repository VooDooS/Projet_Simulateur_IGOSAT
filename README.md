Projet Simulateur IGOSAT
========================

## Documentation
http://voodoos.github.io/Projet_Simulateur_IGOSAT

## Installation
Commencez par cloner le d�p�t dans le dossier de votre choix via l'application github ou la commande:
```git clone https://github.com/VooDooS/Projet_Simulateur_IGOSAT.git```

Ensuite vous pouvez importer les sources, situ�es dans le dossier *IGOsim/src*, directement dans votre IDE (CodeBlocks, VisualC++, XCode..) et lancer la compilation. Ce faisant soyez attentifs � ne pas enregistrer sous git les diff�rents fichiers de configurations propres au logiciel choisi (via le fichier .gitignore par exemple).

~~Il est �galement possible (ou presque.....), sous Linux, de compiler directement en invoquant la commande `make` depuis le dossier *src*.~~



## G�n�ration de la documentation
Le projet utilise [*doxygen*](http://www.stack.nl/~dimitri/doxygen/index.html) pour g�n�rer sa documentation. Un fichier de configuration est fourni, nomm� *doxy.conf*.

Pour g�n�rer manuellement la doc il suffit de se placer dans le r�pertoire *src* et de lancer la commande:
```doxygen doxy.conf```
