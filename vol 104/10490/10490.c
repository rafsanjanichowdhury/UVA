#include <stdio.h>
#include <math.h>

int main()
{
	int input;
	char arr[31][100]={
	"Given number is NOT prime! NO perfect number is available.",
	"Perfect: 6!",
	"Perfect: 28!",
	"Given number is NOT prime! NO perfect number is available.",
	"Perfect: 496!",
	"Given number is NOT prime! NO perfect number is available.",
	"Perfect: 8128!",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is prime. But, NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Perfect: 33550336!",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Perfect: 8589869056!",
	"Given number is NOT prime! NO perfect number is available.",
	"Perfect: 137438691328!",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is prime. But, NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Given number is prime. But, NO perfect number is available.",
	"Given number is NOT prime! NO perfect number is available.",
	"Perfect: 2305843008139952128!"
	};

	while (1)
	{
		scanf("%d",&input);
		if (!input)
			return 0;
		puts(arr[input-1]);
	}
}