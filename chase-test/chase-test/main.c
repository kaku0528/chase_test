#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int CCB()
{

	return rand() % 100 + 1;
}


int meboshi()
{
	int i = 0, j = 0;
	int clear = 0,loop = 1000000;
	double P = 0;

	//�l�l�S���ڐ������l�ŒN����l�ł��ʂ���m��

	srand(time(NULL));


	for (i = 0; i < loop; i++)
	{
		while (j < 4)
		{
			if (CCB() <= 50)
			{
				clear++;
				break;
			}
			j++;
		}
		j = 0;
	}
	P = (double)clear / (double)loop;

	printf("��������m����%.2f%�ł��B\n\n",P*100);

	return 0;
}

int chase()
{
	// �X�e�[�^�X�ݒ�A�ς���Ȃ炱��
	int STR = 10, CON = 10, HP_f = 10, lucky = 90;

	//��������G��Ȃ�
	int  loop = 1000000, clear = 0, HP2 = 0;
	double P = 0;

	int i = 0;

	srand(time(NULL));

	while (lucky >= 15)
	{
		for (i = 0; i < loop; i++)
		{
			int HP = HP_f, N = 10,
				luck = lucky - (rand() % 10 + 1) * 10;
			if (luck < 5)
				luck = 5;

			while (1)
			{

				//�@ STR*5�ŉj��
				if (CCB() <= STR * 5)
				{
					//�A �����Ȃ�K�^����
					if (CCB() <= luck)
					{
						clear++;
						break;
					}
					else
					{
						luck += 10;
					}
				}

				//�B �������[��
				if (CCB() > CON * N)
				{
					HP2 = rand() % 6 + 1;
					if (HP <= HP2 * 2)
					{
						//�V���b�N���[��
						if (CCB() > CON * 5)
						{
							break;
						}
					}

					//HP���炷
					HP -= HP2;

					//2�ȉ��Ŏ����C��
					if (HP < 2)
					{
						break;
					}
				}

				if (N > 1)
					N--;
			}
		}

		P = (double)clear / (double)loop;
		printf("HP=%d\tSTR=%d\tCON=%d\t�K�^=%d\n", HP_f, STR, CON, lucky);
		printf("�N���A����%.2f���ł��B\n\n", P * 100);

		clear = 0;

		lucky = lucky - 5;
		//if (CON % 2 == 0)
		//	HP_f--;
	}
}

int DICE()
{

	int DICE = 5;
	int success = 0, loop = 10000000, i = 0;
	srand(time(NULL));


	double P = 0;

	while (DICE < 100)
	{

		for (i = 0; i < loop; i++)
		{
			if (CCB() <= DICE)
				success++;
		}

		P = (double)success / (double)loop;

		printf("%d�̐�������%.2f%�ł��B\n\n", DICE, P * 100);

		DICE = DICE + 5;
		success = 0;
	}

	return 0;
}


int main()
{
	meboshi();

	return 0;
}