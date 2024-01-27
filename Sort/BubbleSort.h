#pragma once
#include <set>

/**
 * @brief
 * https://en.wikipedia.org/wiki/Bubble_sort\n
 * ��� �ð� ���⵵ : O(N^2)\n
 * �־� �ð� ���⵵ : O(N^2)\n
 * �޸� ���⵵ : O(1)\n
 * ������ : O
 *
 * @param InBegin ������ ������ �������� ���� �ּ�(std::begin)
 * @param InEnd ������ ������ �������� �� �ּ�(std::end)
 */
void BubbleSort(auto* const InBegin, auto* const InEnd)
{
	// ����� ������ŭ �ݺ�
	for (ptrdiff_t Iteration = 0; Iteration < InEnd - InBegin; ++Iteration)
	{
		// ù ��° ��Һ��� ����
		for (auto* CurrentIterator = InBegin; CurrentIterator < InEnd - Iteration; ++CurrentIterator)
		{
			// ���� Ÿ�� ����� ���� ��� �ּ�
			auto NextIterator = CurrentIterator + 1;
			if (NextIterator >= InEnd) { break; }

			auto& CurrentValue = *CurrentIterator;
			auto& NextValue = *NextIterator;

			// ���� Ÿ�� ����� ���� ���� ����� ���� ��
			if (CurrentValue > NextValue)
			{
				// ���� ���ؿ� �����ϸ� swap
				std::swap(CurrentValue, NextValue);
			}
		}
	}
}
