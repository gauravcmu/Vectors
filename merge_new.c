#include <stdio.h>


void m_sort( int a[], int tmp_array[], int left, int right )
{
  /* int tmp_array[N];    why don't we want this? */
  int center;
  if (left < right) {
    center = (left + right) / 2;
    m_sort( a, tmp_array, left, center );
    m_sort( a, tmp_array, center+1, right );
    merge( a, tmp_array, left, center+1, right );
  }
}

void merge( int a[], /* contains all lists, including list 1 and 2 */
            int tmp_array[], /* uses the same locations as a */
            int l_pos,    /* start of left half  - list 1 */
            int r_pos,    /* start of right half - list 2 */
            int right_end /* end of list 2 */               ) {
  int i, left_end, num_elements, tmp_pos;
  
  left_end = r_pos - 1; 
  tmp_pos = l_pos;
  num_elements = right_end - l_pos + 1;
  
  while ( (l_pos <= left_end) && (r_pos <= right_end) )
    if (a[l_pos] <= a[r_pos] )
      tmp_array[tmp_pos++] = a[l_pos++];
    else 
      tmp_array[tmp_pos++] = a[r_pos++];
  
  while (l_pos <= left_end)  tmp_array[tmp_pos++] = a[l_pos++];
  while (r_pos <= right_end) tmp_array[tmp_pos++] = a[r_pos++];
  
  for (i=1; i<=num_elements; i++, right_end-- )
    a[right_end] = tmp_array[right_end];
}

void dump(int A[], int len)
{
    int i;
    printf("\n --------");
    for(i=0; i<len; i++)
    {
        printf("[%d] ", A[i]);
    }
}

int main()
{
    int A[] = { 400, 55, 11, 1, 300};
    int C[5];

    m_sort(A, C, 0, 4);
    dump(C, 5);
}
