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
#include <algorithm>
#include "quick_sort.h"
// ================================================================================

namespace prova
{
	// Tipos basicos utiizados pelas funções.
	using byte = unsigned char;
	using Compare = int(const void*, const void*);
	using UnaryPredicate = bool(const void*);
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
		while(b_last_r < last)
		{
			std::swap(*((int*) b_first_r), *((int*) b_last_r));
			b_last_r+=size;
			b_first_r+=size;
		}
		return b_first_r;
	}

	// Questão 4
	bool contem( const void *first1, const void *last1, const void *first2,
			const void *last2, size_t size, Compare *cmp )
	{
		auto bfirst2 = reinterpret_cast<byte*>(const_cast<void*>(first2));
		byte *bfirst1;
		bool contem;
		while(bfirst2 < last2)
		{	
			contem = false;
			bfirst1  = reinterpret_cast<byte*>(const_cast<void*>(first1));
			while(bfirst1 < last1){
				if(cmp(bfirst1, bfirst2) == 0)
				{
					contem = true;
					break;
				}
				bfirst1+=size;
			}
			if(!contem)
				return false;
			bfirst2+=size;
		}
		return true;
	}

	// Questão 5
	void * remove_repetidos( const void *first, const void *last, const void *value,
			size_t size, Compare *cmp )
	{
		auto bfirst = static_cast<byte*>(const_cast<void*>(first));
		auto blast = static_cast<byte*>(const_cast<void*>(last));
		std::qsort(bfirst, (blast-bfirst)/size, size, cmp);// ordena a alista
		std::sort((int*)first, (int*) last);
		byte *fo = nullptr, *llo = blast; // primeira ocorrencia e last da ultima ocorrencia
        while(bfirst < last) // procura a primeira ocorrencia do valor
        {
            if(fo)
            {
                if(cmp(bfirst, value) != 0)
                {
                    llo = bfirst;
                    break;
                }
            }
            else if(cmp(bfirst, value) == 0)
            {
                fo = bfirst;
            }
            bfirst+=size;
        }
        if(fo){
            std::cout << (blast-fo)/size;
            memcpy(fo, llo, blast - llo);
            return blast - (llo - fo); // last menos quantidade de ocorrencias
        }
		return blast;
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
int pred(const void * a, const void * b)
{
	int * ia = reinterpret_cast<int*>(const_cast<void*>(a));
	int * ib = reinterpret_cast<int*>(const_cast<void*>(b));
	if(*ia < *ib)return -1;
	if(*ia > *ib)return 1;
	else return 0;
}
int compare_ints( const void * a, const void * b )
{
	int *ia = (int*) a, *ib = (int*) b;
	if(*ia < *ib)
		return -1;
	if(*ia > *ib)
		return 1;	
	return 0;
}



int main( )
{
	size_t score = 0;
	size_t total = 120; // Pontos das 2 primeiras questões.
	std::cout << ">>> Voce inicia a prova com " << score << " pontos (de " << total << ").\n\n";
/*
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
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n";


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
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n";


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
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n";


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
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n";


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
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n";


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
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n";


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
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n";


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
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n";

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
	// Questao 3 - teste: remove
	// ================================================================================
	{
		std::cout << ">>> Q3-a: testando a funcao remove(): removendo no meio\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		int R[] = {1, 3, 2, 4, 6, 8, 10};
		auto result = prova::remove( std::begin(A), std::end(A), std::begin(A)+2, std::begin(A)+5, sizeof(int));	
		if (std::memcmp(A, R, std::distance((prova::byte*) A, (prova::byte*) result)) != 0)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	{
		std::cout << ">>> Q3-b: testando a funcao remove(): removendo todos\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		int R[] = {};
		auto result = prova::remove( std::begin(A), std::end(A), std::begin(A), std::end(A), sizeof(int));	
		if ( result != std::begin(A) || std::memcmp(A, R, std::distance((prova::byte*) A, (prova::byte*) result)) != 0)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	{
		std::cout << ">>> Q3-c: testando a funcao remove(): removendo no inicio\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		int R[] = {7, 9, 2, 4, 6, 8, 10};
		auto result = prova::remove( std::begin(A), std::end(A), std::begin(A), std::begin(A)+3, sizeof(int));	
		if (std::memcmp(A, R, std::distance((prova::byte*) A, (prova::byte*) result)) != 0)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	{
		std::cout << ">>> Q3-d: testando a funcao remove(): removendo no final\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		int R[] = {1, 3, 5, 7, 9, 2};
		auto result = prova::remove( std::begin(A), std::end(A), std::begin(A)+6, std::end(A), sizeof(int));	
		if (std::memcmp(A, R, std::distance((prova::byte*) A, (prova::byte*) result)) != 0)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";*/
	// ================================================================================
	// Questao 4 - teste: contem
	// ================================================================================
	{
		std::cout << ">>> Q4-a: testando a funcao contem(): elementos contidos e nao contidos\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		int B[] = {8, 7, 22, 8};
		bool esperado = false;
		auto result = prova::contem( std::begin(A), std::end(A), std::begin(B), std::end(B), sizeof(int), compare_ints);	
		if (result != esperado)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	{
		std::cout << ">>> Q4-b: testando a funcao contem(): nao contidos\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		int B[] = {11, 12, 13, 14};
		bool esperado = false;
		auto result = prova::contem( std::begin(A), std::end(A), std::begin(B), std::end(B), sizeof(int), compare_ints);	
		if (result != esperado)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	{
		std::cout << ">>> Q4-c: testando a funcao contem(): elementos contidos\n";

		int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
		int B[] = {1};
		bool esperado = true;
		auto result = prova::contem( std::begin(A), std::end(A), std::begin(B), std::end(B), sizeof(int), compare_ints);	
		if (result != esperado)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";
	// ================================================================================
	// Questao 4 - teste: remove_repetidos
	// ================================================================================
	{
		std::cout << ">>> Q5-a: testando a funcao remove_repetidos(): elementos repetidos aleatoriamente posicinados\n";
        using namespace std;
		int A[] = {4, 6, 2, 8, 7};
        //int A[] = {5, 3, -3, 6, -7, -4, 3, 2, -1, 15, 2, 5, 1, 9, 10};
        //	print array
        cout << "Array A: [ ";
        copy(A, end(A), ostream_iterator<int>(cout, " "));
        cout << "]\n";
        // print result
        graal::qsort(begin(A), end(A)-begin(A), sizeof(int),  &pred);
        cout << "Array A sorted: [ ";
        copy(A, end(A), ostream_iterator<int>(cout, " "));
        cout << "]\n";
	}
	{
		std::cout << ">>> Q5-b: testando a funcao remove_repetidos(): elementos repetidos no inicio\n";

		int A[] = { 1, 1, 1, 4, 6, 2, 8, 7, 2};
		int R[] = {2, 2, 4, 6, 7, 8};
		int value = 1;
		auto result = prova::remove_repetidos( std::begin(A), std::end(A), (const void*) &value, sizeof(int), compare_ints);	
		if (std::memcmp(A, R, std::distance((prova::byte*) A, (prova::byte*) result)) != 0)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	{
		std::cout << ">>> Q5-c: testando a funcao remove_repetidos(): elementos repetidos no final\n";

		int A[] = {4, 6, 2, 8, 7, 2, 1, 1, 1};
		int R[] = {2, 2, 4, 6, 7, 8};
		int value = 1;
		auto result = prova::remove_repetidos( std::begin(A), std::end(A), (const void*) &value, sizeof(int), compare_ints);	
		if (std::memcmp(A, R, std::distance((prova::byte*) A, (prova::byte*) result)) != 0)
		{
			std::cout << "    Sua resposta estah incorreta!\n";
		}
		else
		{
			score += 5;
			std::cout << "    Sua resposta estah correta!\n";
		}
	}
	{
		std::cout << ">>> Q5-d: testando a funcao remove_repetidos(): nenhum elemento encontrado\n";

		int A[] = {4, 6, 2, 8, 7};
		int R[] = {2, 4, 6, 7, 8};
		int value = 1;
		auto result = prova::remove_repetidos( std::begin(A), std::end(A), (const void*) &value, sizeof(int), &compare_ints);	
        std::cout << "Array A: [ ";
		std::copy(A, std::end(A), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "]\n";
	
        if (std::memcmp(A, R, std::distance((prova::byte*) A, (prova::byte*) result)) != 0)
        {
		   std::cout << "    Sua resposta estah incorreta!\n";
        }
        else
        {
		   score += 5;
		   std::cout << "    Sua resposta estah correta!\n";
        }
	}
	std::cout << ">>> Seus pontos: " << score << " (de " << total << ").\n\n";
	std::cout << "\n\n>>> Normal exiting...\n";
	return EXIT_SUCCESS;

}
