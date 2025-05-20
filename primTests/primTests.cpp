#include "pch.h"
#include "CppUnitTest.h"

#include "../ASD_L10/graph.h"
#include "../ASD_L10/graph.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace primTests
{
	TEST_CLASS(primTests)
	{
	public:
		
		TEST_METHOD(normalAnswer)
		{
			std::vector<std::vector<std::pair<int, int>>> graph(4);

			graph[0].emplace_back(1, 1);
			graph[0].emplace_back(2, 3);
			graph[1].emplace_back(0, 1);
			graph[1].emplace_back(2, 2);
			graph[2].emplace_back(0, 3);
			graph[2].emplace_back(1, 2);
			graph[2].emplace_back(3, 4);
			graph[3].emplace_back(2, 4);

			auto ans = primMST(graph, 0);
			Assert::AreEqual(ans, 7);
		}
        TEST_METHOD(singleNode)
        {
            std::vector<std::vector<std::pair<int, int>>> graph(1);
            auto ans = primMST(graph, 0);
            Assert::AreEqual(ans, 0);
        }

        TEST_METHOD(negativeWeights)
        {
            std::vector<std::vector<std::pair<int, int>>> graph(3);

            graph[0].emplace_back(1, -3);
            graph[0].emplace_back(2, 5);
            graph[1].emplace_back(0, -3);
            graph[1].emplace_back(2, 2);
            graph[2].emplace_back(0, 5);
            graph[2].emplace_back(1, 2);

            auto ans = primMST(graph, 0);
            Assert::AreEqual(ans, -1);
        }

        TEST_METHOD(equals)
        {
            std::vector<std::vector<std::pair<int, int>>> graph(3);

            
            graph[0].emplace_back(1, 5);
            graph[0].emplace_back(1, 3); 
            graph[0].emplace_back(2, 4);
            graph[1].emplace_back(0, 5);
            graph[1].emplace_back(0, 3);
            graph[1].emplace_back(2, 2);
            graph[2].emplace_back(0, 4);
            graph[2].emplace_back(1, 2);

            auto ans = primMST(graph, 0);
            Assert::AreEqual(ans, 5); 
        }

        TEST_METHOD(AnswerEquality)
        {
            std::vector<std::vector<std::pair<int, int>>> graph(4);

            
            graph[0].emplace_back(1, 1);
            graph[0].emplace_back(2, 3);
            graph[1].emplace_back(0, 1);
            graph[1].emplace_back(2, 2);
            graph[2].emplace_back(0, 3);
            graph[2].emplace_back(1, 2);
            graph[2].emplace_back(3, 4);
            graph[3].emplace_back(2, 4);

           
            auto ans = primMST(graph, 3);
            Assert::AreEqual(ans, 7); 
        }

        TEST_METHOD(allZero)
        {
            std::vector<std::vector<std::pair<int, int>>> graph(3);

            graph[0].emplace_back(1, 0);
            graph[0].emplace_back(2, 0);
            graph[1].emplace_back(0, 0);
            graph[1].emplace_back(2, 0);
            graph[2].emplace_back(0, 0);
            graph[2].emplace_back(1, 0);

            auto ans = primMST(graph, 0);
            Assert::AreEqual(ans, 0);
        }
	};
}
