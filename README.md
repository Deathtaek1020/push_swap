# push_swap (version compacte radix)

Tri de pile avec peu de code/fichiers, via:
- Compression d'indices (0..n-1)
- Tri radix binaire (LSD): on pousse les 0 sur B, on rotate les 1, bit par bit.

Seules les opérations nécessaires sont émises: `sa`, `pb`, `pa`, `ra`.

## Build
```
make
```

## Usage
```
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3" "6 5" 8
```

- Affiche sur stdout la suite d'opérations.
- En cas d'entrée invalide (non-entier, overflow int32, doublon), écrit `Error\n` sur stderr et quitte avec code 1.

## Structure
- includes/push_swap.h
- src/: main.c, parse.c, ops.c, stack.c, radix.c
- lib/mini_libft/: ft_split.c, ft_utils.c

## Notes
- Linux, cc -Wall -Wextra -Werror
- Parsing robuste sans dépendances externes
- Optimisation minimale pour n=2 (`sa`)
- Suffisant pour le mandatory; possibilité d'ajouter des optimisations small cases ou une stratégie LIS plus tard.
