/**!
 *  Program usado na avaliação de LP1, 2017.1
 *  @date 11 de abrill de 2017
 */

#include <iostream>  // cout, endl
#include <iomanip>   // setw
#include <iterator>  // distance
#include <cstdlib>   // memset, memcmp, memcpy
#include <cassert>   // assert()
#include <cstring>
#include <functional>

// ================================================================================

namespace prova
{
	// Tipos basicos utiizados pelas funções.
	using byte = unsigned char;
	using Compare = int(const void*, const void*);
	using UnaryPredicate = bool(const void*);
	using value_type = int;
	using CompareOne = std::function<bool(value_type, value_type)>;
	void merge( value_type *l_first, value_type *l_last, // [l_first; l_last)
	     value_type *r_first, value_type *r_last, // [r_first; r_last)
	     value_type *a_first, CompareOne comp= std::less<value_type>() )
	     {
		     int size = (r_last-r_first) + (l_last-l_first); 
		     value_type* a_last = a_first + size; 
		     while(a_first < a_last)
		     {
			     if(l_first == l_last) // copia o resto da direita para A
			     {
				     memcpy(a_first, r_first, (r_last-r_first)*sizeof(value_type)); // A = r_first ate r_last
				     return;
			     }	
			     if(r_first == r_last) // copia o resto da esquerda para A
			     {
				     memcpy(a_first, l_first, (l_last-l_first)*sizeof(value_type)); // A = l_first ate l_last
				     return;
			     }
			     if(*l_first < *r_first)
				     *a_first = *l_first++;
			     else
				     *a_first = *r_first++;
			     a_first++;	
		     }
	     }

	void merge_sort(value_type* first, value_type* last, CompareOne comp= std::less<value_type>())
	{
		// divide array
		// Find out the size of the first half.
		if(last - first < 2)
			return;
		auto m( (last-first) / 2 );

		// Create the left and right auxiliary arrays.
		auto L_sz = m; // `L` size.
		auto R_sz = (last-first)-L_sz; // `R` has the size of `A` minus the size of `L`.
		value_type *L = new value_type[ L_sz ]; // Dynamic allocation.
		value_type *R = new value_type[ R_sz ];

		// Copy elements from each sorted halves of 'A', respectively into 'L' and 'R'.
		std::copy( first, first+m, L );
		std::copy( first+m, last, R );

		merge_sort(L, L+L_sz, comp); // lado direito
		merge_sort(R, R+R_sz, comp); // lado direito
		// Merge the two sorted halves back into array 'A'.
		merge( L, L+L_sz, R, R+R_sz, first);

		// Free auxiliary memory to avoid any memory leak.
		delete [] L;
		delete [] R;
	}
	// Questão 1
	bool eh_particionada( const void * first, const void * last, size_t size,
			UnaryPredicate *p )
	{
		auto fast = reinterpret_cast<byte*>(const_cast<void*>(first));
		auto esperado = p(first);
		while(fast < last)
		{
			if(p(fast) && esperado == false)
			{
				return false;
			}
			if(!p(fast))
				esperado = false;
			fast+=size;
		}	
		return true;
	}

	// Questão 2-a
	const void * limite_inferior( const void *first, const void *last,
			size_t size, const void * value, Compare *cmp )
	{
		auto fast = reinterpret_cast<byte*>(const_cast<void*>(first));
		while(fast < last)
		{
			if(cmp(fast, value) != -1)
				return fast;
			fast+=size;
		}
		return last; 
	}

	// Questão 2-b
	const void * limite_superior( const void *first, const void *last,
			size_t size, const void * value, Compare *cmp )
	{
		auto fast = reinterpret_cast<byte*>(const_cast<void*>(first));
		while(fast < last)
		{
			if(cmp(fast, value) == 1)
				return fast;
			fast+=size;
		}
		return last; 
	}

	// Questão 3
	void * remove( const void *first, const void *last, const void *first_r,
			const void *last_r, size_t size )
	{
		auto b_first_r = reinterpret_cast<byte*>(const_cast<void*>(first_r));
		auto b_last_r = reinterpret_cast<byte*>(const_cast<void*>(last_r));
		auto b_last = reinterpret_cast<byte*>(const_cast<void*>(last));
		memcpy(b_first_r, b_last_r, b_last-b_last_r);
		return b_last - (b_last_r-b_first_r);
	}

	// Questão 4
	bool contem( const void *first1, const void *last1, const void *first2,
			const void *last2, size_t size, Compare *cmp )
	{
		auto fast = reinterpret_cast<byte*>(const_cast<void*>(first1));
		byte *slow;
		bool contem;
		while(fast < last1)
		{	
			contem = false;
			slow  = reinterpret_cast<byte*>(const_cast<void*>(first2));
			while(slow < last2){
				if(cmp(slow, fast) == 0)
				{
					contem = true;
					break;
				}
				slow+=size;
			}
			if(!contem)
				return false;
			fast+=size;

		}
		return true;
	}

	// Questão 5
	void * remove_repetidos( const void *first, const void *last, const void *value,
			size_t size, Compare *cmp )
	{
		// orderna lista
		value_type* i_first = (value_type*) first;
		value_type* i_last = (value_type*) last;
		auto b_last = (byte*) last;
		merge_sort(i_first, i_last);
		auto fast = reinterpret_cast<byte*>(const_cast<void*>(first)) + size;
		while(fast < b_last)
		{
			if(cmp(fast, fast-size) == 0)
			{
				memcpy(fast, fast+size, std::distance(fast+size, (byte*) last));
				b_last-=size;
			}
			fast+=size;
		}
		return (void*) b_last; 
	}
} // namespace prova


// ================================================================================
// CLIENT CODE
// ================================================================================

bool eh_impar( const void *a )
{
	return *((int*) a) % 2 != 0;
}

bool acima_20( const void *a )
{
	return *((int*)a) > 20;
}

int compare_ints( const void * a, const void * b )
{
	int ia = *(int*) a, ib = *(int*) b;
       	if(ia < ib)
		return -1;
	if(ia > ib)
		return 1;	
	return 0;
}



int main( )
{
	size_t score = 0;
	size_t total = 65; // Pontos das 2 primeiras questões.
	std::cout << ">>> Voce inicia a prova com " << score << " pontos (de " << total << ").\n\n";

	// ================================================================================
	// Questao 1 - teste: vetor está particionado
	// ================================================================================
	{
		std::cout << ">>> Q1-a: testando a funcao eh_particionada()\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		// Verificando se o vetor estah particionado com os impares na frente dos pares.
		auto result = prova::eh_particionada( std::begin(A), std::end(A), sizeof(int), eh_impar );
		if ( result == false )
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 10;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

	// ================================================================================
	// Questao 1 - teste:  vetor NÃO está particionado
	// ================================================================================
	{
		std::cout << ">>> Q1-b: testando a funcao eh_particionada()\n";

		int A[] = { 21, 41, 54, 38, 6, 5, 21, 4, 1, -3 };

		// Verificando se o vetor estah particionado com os valores acima de 20 na frente.
		auto result = prova::eh_particionada( std::begin(A), std::end(A), sizeof(int), acima_20 );

		if ( result == true )
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 10;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

	// ================================================================================
	// Questao 2
	// ================================================================================
	{
		std::cout << ">>> Q2-a: testando a funcao limite_inferior(): limite inferior no meio\n";

		int A[] = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
		auto target(4);

		// buscando o limite inferior
		auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( *li == 4 and std::distance(std::begin(A), li) == 7 )
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


	{
		std::cout << ">>> Q2-b: testando a funcao limite_inferior(): valor ausente mas limite inferior no intervalo\n";

		int A[] = { 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 5, 5, 6 };
		auto target(4);

		// buscando o limite inferior
		auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( *li == 5 and std::distance(std::begin(A), li) == 10)
		{
			std::cout << "    Sua resposta estah correta!\n";
			score += 5;
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


	{
		std::cout << ">>> Q2-c: testando a funcao limite_inferior(): limite inferior fora do intervalo\n";

		int A[] = { 1, 1, 2, 3, 3, 3 };
		auto target(5);

		// buscando o limite inferior
		auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( li == std::end(A) )
		{
			std::cout << "    Sua resposta estah correta!\n";
			score += 5;
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


	{
		std::cout << ">>> Q2-d: testando a funcao limite_inferior(): limite inferior no inicio\n";

		int A[] = { 1, 1, 2, 3, 3, 3 };
		auto target(1);

		// buscando o limite inferior
		auto li = (int *) prova::limite_inferior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( li == std::begin(A) )
		{
			std::cout << "    Sua resposta estah correta!\n";
			score += 5;
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


	{
		std::cout << ">>> Q2-e: testando a funcao limite_superior(): valor presente, limite inferior no meio do vetror.\n";

		int A[] = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
		auto target(4);

		// buscando o limite inferior
		auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( *li == 5 and std::distance(std::begin(A), li) == 10 )
		{
			std::cout << "    Sua resposta estah correta!\n";
			score += 5;
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


	{
		std::cout << ">>> Q2-f: testando a funcao limite_superior(): valor ausente, limite superior presente.\n";

		int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
		auto target(4);

		// buscando o limite inferior
		auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( *li == 5 and std::distance(std::begin(A), li) == 7 )
		{
			std::cout << "    Sua resposta estah correta!\n";
			score += 5;
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


	{
		std::cout << ">>> Q2-g: testando a funcao limite_superior(): valor ausente, limite superior fora do intervalo.\n";

		int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
		auto target(7);

		// buscando o limite inferior
		auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( li == std::end(A) )
		{
			std::cout << "    Sua resposta estah correta!\n";
			score += 5;
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";


	{
		std::cout << ">>> Q2-h: testando a funcao limite_superior(): valor no inicio\n";

		int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
		auto target(1);

		// buscando o limite inferior
		auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( *li == 2 and std::distance( std::begin(A), li ) == 2 )
		{
			std::cout << "    Sua resposta estah correta!\n";
			score += 5;
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

	{
		std::cout << ">>> Q2-i: testando a funcao limite_superior(): valor menor que início do intervalo.\n";

		int A[] = { 1, 1, 2, 3, 3, 3, 3, 5, 5, 6 };
		auto target(0);

		// buscando o limite inferior
		auto li = (int *) prova::limite_superior( std::begin(A), std::end(A), sizeof(int),
				&target, compare_ints );

		if ( *li == 1 and li == std::begin(A) )
		{
			std::cout << "    Sua resposta estah correta!\n";
			score += 5;
		}
		else
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";

	// ================================================================================
	// TODO: Inclua aqui seus testes para as questões 3, 4 e 5.
	// ================================================================================


	// ================================================================================
	// Questao 3 - teste: remove
	// ================================================================================
	{
		std::cout << ">>> Q3-a: testando a funcao remove()\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		auto result = prova::remove( std::begin(A), std::end(A), std::begin(A)+2, std::begin(A)+5, sizeof(int));
		if ( result == std::begin(A)+7)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 10;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";
	std::cout << "\n\n>>> Normal exiting...\n";
	return EXIT_SUCCESS;

}
