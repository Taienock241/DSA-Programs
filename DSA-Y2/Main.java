public class Main {
    public static void main(String[] args) {
        int[] array = {12, 11, 13, 5, 6, 7, 8, 56, 45, 85, 2, 54, 33, 11};

        mergesort(array);

        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }

    private static void mergesort(int[] array) {
        int length = array.length;
        if (length < 2) {
            return;
        }

        int mid = length / 2;
        int[] left = new int[mid];
        int[] right = new int[length - mid];

        for (int i = 0; i < length; i++) {
            if (i < mid) {
                left[i] = array[i];
            } else {
                right[i - mid] = array[i];
            }
        }

        mergesort(left);
        mergesort(right);
        merge(left, right, array);
    }

    private static void merge(int[] left, int[] right, int[] array) {
        int i = 0;
        int l = 0;
        int r = 0;

        while (l < left.length && r < right.length) {
            if (left[l] < right[r]) {
                array[i] = left[l];
                l++;
            } else {
                array[i] = right[r];
                r++;
            }
            i++;
        }

        while (l < left.length) {
            array[i] = left[l];
            i++;
            l++;
        }

        while (r < right.length) {
            array[i] = right[r];
            i++;
            r++;
        }
    }
}
