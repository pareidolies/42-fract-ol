# Fract'ol

![mandelbrot](https://user-images.githubusercontent.com/96736158/176945434-98e6fdc4-20b8-4d44-beb0-0771e4b98b23.png)

Ce projet graphique permet de générer de l'art fractal sur Linux. C'est jusqu'à présent mon projet préféré de tout mon cursus à 42. Voici un mode d'emploi si vous souhaitez 'git clone' mon projet pour découvrir le rendu, puis à la suite mes explications et recommandations si vous souhaitez le réaliser vous-même (ce que je vous encourage très sincèrement à faire !).

# Mode d'emploi de ce projet

[A COMPLETER]

Et maintenant à vous de jouer ! Voici toutes mes recommandations pour aborder l'énoncé donné par 42 de la meilleure des manières.

# La Minilibx

Premièrement, pour vous familiariser avec la Minilibx créée par des étudiants de 42, je vous recommande chaudement, en plus du très connu 42 Docs, le travail de pédagogie qu'a réalisé Aurélien Brabant, un étudiant à 42, et plus précisément ces 3 articles de son blog (à consulter dans cet ordre) :

* Getting Started with the Minilibx : https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx 
* Managing Events with the Minilibx : https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx
* Pixel Drawing with the Minilibx : https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

# La Théorie des Fractales

Concernant la théorie mathématique derrière les fractales, ne soyez surtout pas inquiets ! Vous verrez qu'elle est en réalité très simple, du moins pour ce qui nous est demandé dans ce projet. Si vous savez ce qu'est une suite et un nombre complexe, vous aurez déjà quasiment tous les éléments pour créer les superbes fractales de Julia et de Mandelbrot. Voici les seules ressources dont j'ai eu besoin :

* https://fr.wikipedia.org/wiki/Fractale
* https://fr.wikipedia.org/wiki/Ensemble_de_Julia

Il y a également bien sûr de nombreux livres de mathématiciens sur le sujet si vous souhaitez creuser l'aspect mathématique ! Par ailleurs, si le sujet vous intéresse d'un point de vue plus philosophique, n'hésitez pas à creuser davantage en allant voir les vidéos de MicMaths (https://www.youtube.com/watch?v=iFA3g_4myFw) ou en tapant "Théorie du Chaos" sur Google, ce sont vraiment des sujets passionnants.  Enfin, d'un point de vue historique, la biographie de Mandelbrot, le rôle de l'informatique dans la recherche sur les fractales et les différentes applications de la théorie (en finance, économie, etc) sont également vraiment très intéressants.

# Dessiner des Fractales en langage C

A présent, tout l'enjeu va être de dessiner ces fameuses fractales sur votre écran ! Pour ce faire, il existe plusieurs tutoriels sur internet, notamment :
* https://www.codequoi.com/en/fract-ol-generating-fractals-in-c/
* https://www.geeksforgeeks.org/fractals-in-cc/

Je vais tout de même vous expliquer rapidement la méthode avec mes mots : 

[A COMPLETER]

N'hésitez pas à créer votre propre palette de couleurs en réalisant des tests selon vos propres goûts. Ce site génère de très belles combinaisons de couleurs aléatoires (avec leurs codes RGB bien sûr) : https://coolors.co/c52233-a51c30-a7333f-74121d-580c1f

# Quelques rendus

Par pure fierté, voici quelques fractales que j'ai réussi à dessiner :

L'ensemble de Mandelbrot :

![mandelbrot 2](https://user-images.githubusercontent.com/96736158/176944181-1019b96a-dd38-42d6-8251-d129fc600ba0.png) 

![mandelbrot 3](https://user-images.githubusercontent.com/96736158/176944286-d2d484fb-bfd9-412e-82f0-bfe83b0e5586.png) 

![mandelbrot 4](https://user-images.githubusercontent.com/96736158/176944291-90a7386d-6072-4083-bc12-2a7eb02e9b63.png)

Julia -0.4 0.6 :

![Julia -0 4 0 6](https://user-images.githubusercontent.com/96736158/176944578-37d2cd00-5ddb-4560-acd4-8fd5c6aa5d3c.png)

![Julia -0 4 0 6 (2)](https://user-images.githubusercontent.com/96736158/176944605-f39e8057-bb22-4671-bf16-845bdc9e1071.png)

![Julia -0 4 0 6 (3)](https://user-images.githubusercontent.com/96736158/176944634-3aa13102-c284-4471-ab16-fa208e422982.png)

Julia 0.285 0.01 :

![julia 0 285 0 01](https://user-images.githubusercontent.com/96736158/176945006-208a3fb8-c776-461f-a8f8-fc4c9c89428b.png)

![julia 0 285 0 01 (2)](https://user-images.githubusercontent.com/96736158/176945036-6aa05fd8-5903-4cf3-8c79-4efca9f63531.png)

Julia 0.3555534 -0.337292 :

![Julia 0 3555534 -0 337292](https://user-images.githubusercontent.com/96736158/176945211-c2c8d099-4fde-42cf-a0d2-261258c91327.png)

![Julia 0 3555534 -0 337292 (2)](https://user-images.githubusercontent.com/96736158/176945220-7bf6bcc4-a876-4467-99fe-39e004275536.png)

![Julia 0 3555534 -0 337292 (3)](https://user-images.githubusercontent.com/96736158/176945226-0c80cd47-6824-4aca-be2f-b74041270112.png)

Julia 0.355 0.355 :

![Julia 0 355 0 355 (2)](https://user-images.githubusercontent.com/96736158/176945307-8afc6b34-7844-4e2b-863f-eebeddb1bcf8.png)

![Julia 0 355 0 355](https://user-images.githubusercontent.com/96736158/176945321-a7dc23f2-63b2-4224-8cfd-156434184776.png)

![Julia 0 355 0 355 (3)](https://user-images.githubusercontent.com/96736158/176945326-0bef1656-ce10-465e-b05f-f7d9436c9920.png)

Julia -0.54 0.54 :

![Julia -0 54 0 54 ](https://user-images.githubusercontent.com/96736158/176945358-e5ba8880-8bca-406f-8e74-868e705b1099.png)

![Julia -0 54 0 54 (2)](https://user-images.githubusercontent.com/96736158/176945362-d72d7fb5-d3f9-4531-8c1f-76f053202c0f.png)

![Julia -0 54 0 54 (3)](https://user-images.githubusercontent.com/96736158/176945365-cbdaafc8-89a9-4ac3-8da1-f8b281c21188.png)

Burning-Ship :

![burning ship 2](https://user-images.githubusercontent.com/96736158/176945742-72b7633d-1b2d-48f6-958d-756954bd3577.png)

Au départ, on ne voit rien de très fascinant... Mais en zoomant en bas à gauche son intitulé prend tout son sens !

![burning ship](https://user-images.githubusercontent.com/96736158/176945808-b98494eb-68e3-4b02-8c5b-b53e6e41cca1.png)

# Mes conseils

Pour terminer, voici quelques conseils généraux  :
- Quand j'avais des bugs qui apparaissaient, dans 80% des cas c'était à cause d'une mauvaise conversion / utilisation des int et des float.
- Utilisez les images de la minilibx, surtout pas la fonction put pixel.
- Burning Ship est un bonus vraiment très facile à faire, mais il existe beaucoup d'autres très belles fractales (Sierpinski par exemple).
- Pour éviter les ralentissements dans l'utilisation du zoom et les déplacements, mieux vaut se contenter d'une fenêtre relativement petite et d'un nombre d'itérations relativement restreint. Par ailleurs, il faut exécuter la minilibx à partir du Makefile (allez voir le Makefile pour comparer avec le vôtre, un ralentissement pourrait venir de là) !



