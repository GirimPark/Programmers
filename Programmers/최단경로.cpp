/*

#include <iostream>
#include <vector>
using namespace std;

vector<int> Dijkstra(vector<vector<pair<int, int>>> graph, int vertexCnt, int startVertex)
{
	vector<int> answer(vertexCnt + 1, INT32_MAX);
	vector<bool> visited(vertexCnt + 1, false);
	
	int curVertex = startVertex;
	answer[curVertex] = 0;
	visited[curVertex] = true;

	// 시작정점과 연결된 정점 거리 확정, 다음 방문 노드 지정
	int min = INT32_MAX;
	for (const auto& pair : graph[curVertex])
	{
		int arrival = pair.first; int w = pair.second;
		if (w < answer[arrival])
		{
			answer[arrival] = w;
		}
		if (w < min)
		{
			curVertex = arrival;
			min = w;
		}
	}
	
	while (!graph[curVertex].empty())
	{
		visited[curVertex] = true;
		if (graph[curVertex].empty())	break;
		// 현재 노드에 연결된 노드들의 최단 거리 갱신
		for (const auto& pair : graph[curVertex])
		{
			int arrival = pair.first; int w = pair.second;
			if (!visited[arrival] && answer[curVertex] + w < answer[arrival])
			{
				answer[arrival] = answer[curVertex] + w;
			}
		}

		// 노드 이동하기
		min = INT32_MAX;
		for (int i = 1; i < answer.size(); i++)
		{
			if (!visited[i] && answer[i] < min)
			{
				min = answer[i];
				curVertex = i;
			}
		}
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E, K;	// 정점 개수, 간선 개수, 시작 정점
	cin >> V >> E >> K;

	vector<vector<pair<int, int>>> graph(V + 1);	// 출발정점, <도착정점, 가중치>
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(pair<int, int>(v, w));
	}

	vector<int> answer = Dijkstra(graph, V, K);
	for (int i = 1; i <= V; i++)
	{
		if (answer[i] == INT32_MAX)
			cout << "INF\n";
		else
			cout << answer[i] << '\n';
	}

	return 0;
}

*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

std::vector<int> Dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph, int vertexCnt, int startVertex)
{
	std::vector<int> answer(vertexCnt + 1, std::numeric_limits<int>::max());
	answer[startVertex] = 0;

	// <가중치, 도착노드>
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push({ 0, startVertex });

	while (!pq.empty())
	{
		int curVertex = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (answer[curVertex] < curDist) continue;

		for (const auto& pair : graph[curVertex])
		{
			int arrival = pair.first;
			int w = pair.second;
			int newDist = curDist + w;

			if (newDist < answer[arrival])
			{
				answer[arrival] = newDist;
				pq.push({ newDist, arrival });
			}
		}
	}

	return answer;
}

using namespace std;

vector<int> Dijkstra2(const vector<vector<pair<int, int>>>& graph, int vertexCnt, int startVertex)
{
	vector<int> answer(vertexCnt + 1, INT32_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	answer[startVertex] = 0;
	pq.push({ 0, startVertex });
	int curVertex = startVertex;

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		for (const auto& pair : graph[curVertex])
		{
			int arrival = pair.first;
			int w = pair.second;
			int newDist = curDist + w;

			if (newDist < answer[arrival])
			{
				answer[arrival] = newDist;
				pq.push({ w, arrival });
			}
		}
	}

	return answer;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int V, E, K; // 정점 개수, 간선 개수, 시작 정점
	std::cin >> V >> E >> K;

	std::vector<std::vector<std::pair<int, int>>> graph(V + 1); // 출발정점, <도착정점, 가중치>
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		std::cin >> u >> v >> w;
		graph[u].push_back(std::make_pair(v, w));
	}

	std::vector<int> answer = Dijkstra(graph, V, K);
	for (int i = 1; i <= V; i++)
	{
		if (answer[i] == std::numeric_limits<int>::max())
			std::cout << "INF\n";
		else
			std::cout << answer[i] << '\n';
	}

	return 0;
}