TODOLIST

- gerer les obstacles blocs lors de la collision :
  - rebond correct de la ball
  - le bloc doit disparaitre si detruit (modifie le int **tab)
    - lorsque la balle touche le bloc, ifwin(win);
- ajout des blocs normaux (1 a 10), invincibles (>=30)
    et destructibles en 3 etapes (20 a 29)
- ajout d'un score (affichage ?)
- ajout d'un compteur de vies (affichage ?)
- perdre :
  - la boule passe en dessous de y = -1
  - compteur de vies decremente
- gagner :
  - 0 blocs restants hors blocs indestructibles
  - gagner == niveau suivant
