/*
	DFS - Template II

	@Note : Please mark the note here that if your depth of recursion is too high, than
	recursion will not work most of the cases even if you have implemented it using the 
	memoization.

	So in that scenario, the one approach which i can visualise from the problem is to use BFS.

	Incase you are very facinated with Stack and recursion than another choice here is to create your 
	own stack and use that in your solution instead of using system stack.

	// So below is the template for using own stack which implementing the DFS

	boolean DFS(int root, int target)
	{
		unordered_set<Node*> visited;
		stack<Node*> stk;

		add root to the stack

		while(stack is not empty) {
			Node curr = the top element in the stack;
			remove the top element from the stack;

			return true if the curr is equal to target;

			for(auto next : the neighbours of curr) {
				if(next is not visited) {
					add next into visited;
					add next into the stack;
				}
			}
		}
		return false;
	}

	The logic is exactly the same with the recursion solution. 
	But we use while loop and stack to simulate the system call stack during recursion.


*/