double maior_soma(node * head)
{
    double soma = 0.0;
    #pragma omp taskgroup task_reduction(+: soma)
    {
        node * x = head;
        while (x != null) {
            #pragma omp task in_reduction(+: soma)
            soma += x->value;
            x = x->next;
        }
    }
    return soma;
}