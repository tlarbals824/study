# study
인프런 강의:it 취업을 위한 알고리즘 문제풀이 (with C/C++) : 코딩테스트 대비

1~25는 노션 페이지에 올림, 26이후로는 깃허브에도 올리겠음
강의에서 나오는 코드가 아니라 내가 짜고 잘돌아가고 문제의도랑 같으면 올림
노션:https://www.notion.so/it-with-C-C-6784b44ce6cd43c294e044b794ac52c8



백준 code.plus 문제 하나씩 풀고 있음
다시 봐야할것들:
10972(다음순열) next_permutation
10973(이전순열) prev_permutation
16940,16964(DFS,BFS) 탐색 순서를 변경하는 방법을 알려줌
14003(조합,이분 탑색) 각 원소를 탑색하면서 증가하는 수열을 만듦, 이때 이분탐색을 이용해서 교체되는 idx을 알 수 있음
1208,2143(이분탐색, 조합) 각 원소를 탐색하면서 그 원소를 집합에 추가할지 계산할 때 2^n계산을 해야한다.
				   		여기서 배열을 둘로 나눠서 계산하면 2^(n/2)으로 줄일수 있다. map이용
						
1644(소수, 두 포인터) 정수n이 주어졌을 때 1~n에서 소수를 찾는 빠른 방법을 알 수 있다.	
1806(두 포인터) 두 포인터를 이용해서 부분합구하기 두 포인터 대표 예
1339(그리디) 한번 한번 선택할 때마다 최선의 선택을 하는 방법, 그리디 대표 예
11404(플로이드 와샬) 각 vertex 간의 거리의 최솟값을 구하는  dp풀이법중 가장 빠른 알고리즘
12865,2133,2225(bottom-up) dp풀이법중 bottom-up 대표 문제
1916,1753(다익스트라) 다익스트라 방법중 nlogn 시간으로 풀 수 있는 문제, priority_queue를 사용함
13023(그래프) 이해하기 좀 어려웠음
2143(이분 탐색) lower_bound,upper_bound 이용해서 두 배열 합 구하는 문제, 이분 탐색 공부하자
