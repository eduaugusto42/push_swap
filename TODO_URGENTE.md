# Build quebrado — main.c foi deletado

main.c foi apagado em duas branches (operations e stack_model) durante a
limpeza, e nunca foi reescrito para chamar as funções novas de operations.h.

Falta escrever main.c chamando:
- parse_command_line() (já existe e funciona)
- stack_init / stack_fill_from_array (já existem)
- as funções de operations.h, que agora pedem (int fd, t_stack *a, t_stats *stats)

Última versão antiga (sem operations.h) pra referência:
git show c2289a4:main.c
