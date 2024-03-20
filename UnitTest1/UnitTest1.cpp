#include "pch.h"
#include "CppUnitTest.h"
#include "../Queue/queue.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestQueuePush)
		{
			Queue<int> q;

			q.push(5);
			Assert::AreEqual(1, q.calculateSize());

			q.push(2);
			Assert::AreEqual(2, q.calculateSize());
		}

		TEST_METHOD(TestQueuePop)
		{
			Queue<int> q;
			q.push(1);
			q.push(2);

			Assert::AreEqual(1, q.pop());
			Assert::AreEqual(1, q.calculateSize());

			Assert::AreEqual(2, q.pop());
			Assert::AreEqual(0, q.calculateSize());
		}

		TEST_METHOD(TestQueueIsEmpty)
		{
			Queue<int> q;
			Assert::IsTrue(q.isEmpty());

			q.push(1);
			Assert::IsFalse(q.isEmpty());

			q.pop();
			Assert::IsTrue(q.isEmpty());
		}

		TEST_METHOD(TestQueueCalculateSize)
		{
			Queue<int> q;
			Assert::AreEqual(0, q.calculateSize());

			q.push(1);
			Assert::AreEqual(1, q.calculateSize());

			q.push(2);
			Assert::AreEqual(2, q.calculateSize());

			q.pop();
			Assert::AreEqual(1, q.calculateSize());

			q.pop();
			Assert::AreEqual(0, q.calculateSize());
		}

		TEST_METHOD(TestPriorityQueuePush)
		{
			PriorityQueue<int> pq;

			pq.push(5, 2);
			Assert::AreEqual(1, pq.calculateSize());

			pq.push(10, 1);
			Assert::AreEqual(2, pq.calculateSize());
		}

		TEST_METHOD(TestPriorityQueuePop)
		{
			PriorityQueue<int> pq;
			pq.push(5, 2);
			pq.push(10, 1);

			Assert::AreEqual(5, pq.pop());
			Assert::AreEqual(1, pq.calculateSize());

			Assert::AreEqual(10, pq.pop());
			Assert::AreEqual(0, pq.calculateSize());
		}

		TEST_METHOD(TestPriorityQueueIsEmpty)
		{
			PriorityQueue<int> pq;
			Assert::IsTrue(pq.isEmpty());

			pq.push(1, 1);
			Assert::IsFalse(pq.isEmpty());

			pq.pop();
			Assert::IsTrue(pq.isEmpty());
		}

		TEST_METHOD(TestPriorityQueueCalculateSize)
		{
			PriorityQueue<int> pq;
			Assert::AreEqual(0, pq.calculateSize());

			pq.push(1, 1);
			Assert::AreEqual(1, pq.calculateSize());

			pq.push(2, 2);
			Assert::AreEqual(2, pq.calculateSize());

			pq.pop();
			Assert::AreEqual(1, pq.calculateSize());

			pq.pop();
			Assert::AreEqual(0, pq.calculateSize());
		}
	};
}
