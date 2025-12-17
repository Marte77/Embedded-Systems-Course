/* @author Geir K. Nilsen (geir.kjetil.nilsen@gmail.com) 2017
 *https://octovoid.com/2017/11/04/coding-a-parametric-equalizer-for-audio-applications/
 * translated from C# to C++ by martinho
 * */
namespace pe
{
    #define NUM_BANDS 7
    #define MAX_FILTER_ORDER 3
    
    // Helper functions for array operations
    void array_copy(const int* src, int* dst, int size) {
        for (int i = 0; i < size; i++) {
            dst[i] = src[i];
        }
    }
    
    void array_resize(int* arr, int old_size, int new_size, int default_value = 0) {
        for (int i = old_size; i < new_size; i++) {
            arr[i] = default_value;
        }
    }
    
    class Filter
    {
    private:
        int a[MAX_FILTER_ORDER];
        int b[MAX_FILTER_ORDER];
        int a_size;
        int b_size;

        int x_past[NUM_BANDS];
        int y_past[NUM_BANDS];
        int x_past_size;
        int y_past_size;

    public:
        Filter(int* a_coeffs, int* b_coeffs, int a_len, int b_len)
            : a_size(a_len), b_size(b_len), x_past_size(0), y_past_size(0)
        {
            array_copy(a_coeffs, a, a_len);
            array_copy(b_coeffs, b, b_len);
        }

        void apply(int* x, int* y, int x_size, int& y_size)
        {
            int ord = a_size - 1;
            int np = x_size - 1;

            if (np < ord)
            {
                // Extend x array if needed
                for (int i = x_size; i <= ord; i++) {
                    x[i] = 0;
                }
                np = ord;
            }

            y_size = np + 1;
            for (int i = 0; i <= np; i++) {
                y[i] = 0;
            }

            if (x_past_size == 0)
            {
                x_past_size = x_size;
                for (int i = 0; i < x_past_size; i++) {
                    x_past[i] = 0;
                }
            }

            if (y_past_size == 0)
            {
                y_past_size = y_size;
                for (int i = 0; i < y_past_size; i++) {
                    y_past[i] = 0;
                }
            }

            for (int i = 0; i <= np; i++)
            {
                y[i] = 0;

                for (int j = 0; j <= ord; j++)
                {
                    if (i - j < 0)
                        y[i] += b[j] * x_past[x_past_size - j - 1];
                    else
                        y[i] += b[j] * x[i - j];
                }

                for (int j = 0; j < ord; j++)
                {
                    if (i - j - 1 < 0)
                        y[i] -= a[j + 1] * y_past[y_past_size - j - 2];
                    else
                        y[i] -= a[j + 1] * y[i - j - 1];
                }

                y[i] /= a[0];
            }

            array_copy(x, x_past, x_size);
            x_past_size = x_size;
            array_copy(y, y_past, y_size);
        }
    };
}
