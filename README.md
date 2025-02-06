# Philosophers

Ce projet implémente une simulation du **problème classique des philosophes** (Dining Philosophers). Il s'agit d'une application multithread en C qui illustre les problématiques de synchronisation, de gestion des ressources partagées et de prévention des deadlocks.

## Présentation

Le but de ce projet est de simuler le comportement de philosophes qui alternent entre réflexion et repas, tout en partageant des ressources limitées (les fourchettes). Chaque philosophe doit obtenir l’accès aux ressources nécessaires pour manger, tout en évitant les situations de blocage (deadlocks) et de famine.

## Fonctionnalités

- **Simulation en temps réel** : Affichage de l’état de chaque philosophe (réflexion, attente, repas).
- **Gestion de la concurrence** : Utilisation de threads pour simuler l’activité simultanée des philosophes.
- **Prévention des deadlocks** : Mise en place d’une stratégie pour éviter le blocage mutuel lors de la prise des fourchettes.
- **Paramétrage dynamique** : Possibilité de définir le nombre de philosophes, les délais de réflexion et de repas, ainsi que d'autres paramètres propres à la simulation.

## Installation

### Prérequis

- Un compilateur C (par exemple, [GCC](https://gcc.gnu.org/))
- [Make](https://www.gnu.org/software/make/) (si un Makefile est fourni)
- [Git](https://git-scm.com/) pour cloner le dépôt

### Étapes d'installation

1. **Cloner le dépôt :**

   ```bash
   git clone https://github.com/Herimamy12/philosophers.git
   ```
2. **Se rendre dans le répertoire du projet :**

   ```bash
   cd philosophers/philo/
   ```

3. **Compiler le projet :**

   ```bash
   make
   ```

## Utilisation

Après compilation, lancez le programme en exécutant :

   ```bash
   ./philo [arguments]
   ```

Les arguments permettent de configurer :
- Le nombre de philosophes.
- Délais d'attente avant de mourrir
- Délais du temps pour manger
- Délais du temps pour dormir
- Nombre de fois qu'un philosophe mange (facultatif)

## Contribution

Les contributions à ce projet sont les bienvenues ! Si vous souhaitez participer, voici les étapes à suivre :

1. Forkez ce projet.
2. Créez une branche pour chaque fonctionnalité ou correction de bug.
3. Assurez-vous que vos modifications ne cassent pas l'existant et que toutes les fonctionnalités sont correctement testées.
4. Soumettez une Pull Request pour que vos modifications puissent être examinées et fusionnées.

Nous vous encourageons également à ajouter des tests unitaires pour garantir la stabilité du projet et éviter toute régression.

#### Auteurs

- [Herimamy12](https://github.com/Herimamy12)
