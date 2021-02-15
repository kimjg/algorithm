# sort

    - 정렬을 하는 이유는 데이터 탐색(binary search)을 위해서이다. 대부분의 경우 삽입/삭제보다는 데이터를 조회하는 것이 압도적으로 많고, 조회에 필요한 것이 바로 검색이다.
    - 이론과 달리, 실제로 돌려보면 의외로 결과가 다르게 나오는 경우가 있다. 주로 하드웨어 입출력이 관여해서, 그부분에 걸리는 시간이 정렬 알고리즘 마다 과하게 달라서 더느려야 하는 알고리즘이 더 빠른 경우가 있다. (ex. quick sort)
    - 하드웨어나 컴파일러 등의 관점에서 정렬을 다룬 논문들이 많으니 참고하자. 실제로 콜스택을 제대로 구현하기 어려운 임베디드 기기용으로는 퀵소트를 더 느린 셸소트로 대체 구현하기도 한다.
    - Big-O 표기법에서는 log의 밑은 밑변환 하면 상수배이기 때문에 상관이 없다. 따라서 log2x, log4x 를 lgx로 줄여 쓴다.
    - 데이터의 상황(분포)에 따라 다른 정렬을 사용하기도 한다. 문자열을 정렬하는 경우(데이터의 종류가 적을 경우) counting 정렬이 효과적이며, 데이터의 분포가 다양하며 많을 경우, 대부분의 하드웨어 아키텍쳐에서 quick 정렬이 효과적이다.
    
	 i.    Bubble Sort
      ii.    Selection Sort
     iii.    Insertion sort
      iv.    Merge sort
       v.    Heap sort
      vi.    Quick sort
     vii.    Radix sort
    viii.    Counting sort
      ix.    Shell's sort
    	