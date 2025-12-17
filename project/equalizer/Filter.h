#define SAMPLE_SIZE 10

class Filter {
public:
    double a[3];
    double b[3];

    double x_past[3];
    double y_past[3];
    Filter() {}
    Filter(double a[3], double b[3]){
        for (int i = 0; i < 3; i++) {
            this->a[i] = a[i];
            this->b[i] = b[i];
            this->x_past[i] = 0;
            this->y_past[i] = 0;
        }
    }

    void apply(double x[3], double y[3])
    {
        int ord = 3 - 1;
        int np = 3 - 1;
        for (int i = 0; i <= np; i++)
        {
            y[i] = 0;
            for (int j = 0; j <= ord; j++)
            {
                if (i - j < 0)
                    y[i] += b[j] * x_past[3 - j - 1];
                else
                    y[i] += b[j] * x[i - j];

                if (j > 0)
                {
                    if (i - j < 0)
                        y[i] -= a[j] * y_past[3 - j - 1];
                    else
                        y[i] -= a[j] * y[i - j];
                }
            }
        }

        // Update past samples
        for (int i = 0; i < 3; i++) {
            x_past[i] = x[i];
            y_past[i] = y[i];
        }
    }
};
