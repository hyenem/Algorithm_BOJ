import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	static int[] preorder, inorder, tree;
	static void findTree(int[] pre, int[] in) {
		if(pre.length==0) {
			return;
		}
		
		int root = pre[0];
		int r;
		for(r=0; r<in.length; r++) {
			if(in[r]==root) break;
		}
		
		int[] left = Arrays.copyOfRange(in, 0, r);
		int[] right = Arrays.copyOfRange(in, r+1, inorder.length);
		
		findTree(Arrays.copyOfRange(pre, 1, r+1), left);
		findTree(Arrays.copyOfRange(pre, r+1, pre.length), right);
		System.out.print(root+" ");
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 0; tc < T; tc++) {
			
			int N = sc.nextInt();
			preorder = new int[N];
			inorder = new int[N];
			
			for(int i=0; i<N; i++) {
				preorder[i] = sc.nextInt();
			}
			for(int i=0; i<N; i++) {
				inorder[i] = sc.nextInt();
			}
			
			findTree(preorder, inorder);
			System.out.println();
		}
	}
}
