#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.1415926535

int checkFibo(int n)
{
    int a = 0, b = 1, c = a + b;
    while (c <= n)
    {
        if (n == c)
        {
            return 1;
        }
        a = b;
        b = c;
        c = a + b;
    }
    return 0;
}

int checkFriendNum(int a, int b)
{
    int sum = 0;
    for (int i = 1; i <= a / 2; i++)
    {
        if (a % i == 0)
        {
            sum += i;
        }
    }
    if (sum == b)
        return 1;
    return 0;
}
int main()
{
    FILE *inputFile, *outputFile;
    int n, dc, dg, ld;
    char w[10];
    if ((inputFile = fopen("input.inp", "r")) == NULL)
    {
        printf("Khong the mo tap tin input.inp\n");
        perror("Loi khi mo tap tin: ");
        return 0;
    }
    fscanf(inputFile, "%d %d %d %d %s", &n, &dc, &dg, &ld, &w);
    fclose(inputFile);
    if ((outputFile = fopen("output.out", "w")) == NULL)
    {
        printf("Khong the mo tap tin output.out\n");
        return 0;
    }

    if (n == 0)
    {
        fprintf(outputFile, "0 0 0");
        fclose(outputFile);
        return 0;
    }
    if (
        (dg == 0 && dc == 0) ||
        n > 2000 ||
        n <= 0 ||
        dc < 0 ||
        dg < 0 ||
        (ld <= 1 || ld >= 600) ||
        (strcmp(w, "Wind") != 0 && strcmp(w, "Rain") != 0 && strcmp(w, "Sun") != 0 && strcmp(w, "Cloud") != 0 && strcmp(w, "Fog") != 0))
    {
        fprintf(outputFile, "-1 -1 %d", n);
        fclose(outputFile);
    }
    double save = n;
    double areaBC = (double)dc * dc * sqrt(dc);
    double areaBG = (double)dg * dg * PI / 3;
    int amountBC = 0;
    int amountBG = 0;
    if (strstr(w, "Wind"))
    {
        double saveOfSave = save;
        int saveLD = ld;
        int worstCase = 0;
        while (save > areaBC && ld >= 1)
        {
            if (dc >= 8)
            {
                if (ld >= 2)
                {
                    amountBC++;
                    save -= areaBC;
                    ld -= 2;
                }
                if ((ld <= 1) && save > areaBC)
                {
                    worstCase = 1;
                    break;
                }
            }
            else
            {
                if (ld >= 1)
                {
                    amountBC++;
                    save -= areaBC;
                    ld -= 1;
                }
                if ((ld == 0) && save > areaBC)
                {
                    worstCase = 1;
                }
            }
        }
        while (save > areaBG && ld >= 1)
        {
            if (dg >= 5)
            {
                if (ld >= 2)
                {
                    amountBG++;
                    save -= areaBG;
                    ld -= 2;
                }
                if (ld == 1)
                    break;
            }
            else
            {
                if (ld >= 1)
                {
                    amountBG++;
                    save -= areaBG;
                    ld -= 1;
                }
            }
        }

        if (worstCase == 0 || (worstCase == 1 && areaBG < areaBC))
        {
            fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
            fclose(outputFile);
        }

        if (worstCase == 1 && areaBG > areaBC)
        {
            double max = 99999;

            int saveAmountBG = 0;
            int saveAmountBC = 0;

            while (saveOfSave > areaBG && saveLD > 0)
            {

                if (dg >= 5)
                {
                    saveOfSave -= areaBG;
                    amountBG++;
                    saveLD -= 2;

                    double storeSave = saveOfSave;
                    int storeLD = saveLD;
                    while (storeSave > areaBC && storeLD > 0)
                    {
                        if (dc >= 8)
                        {
                            storeSave -= areaBC;
                            saveAmountBC++;
                            storeLD -= 2;
                        }
                        else
                        {
                            storeSave -= areaBC;
                            saveAmountBC++;
                            storeLD -= 1;
                        }
                    }

                    if (max > storeSave)
                    {
                        max = storeSave;
                        amountBC = saveAmountBC;
                        saveAmountBG = amountBG;
                    }
                    saveAmountBC = 0;
                }
                else
                {
                    saveOfSave -= areaBG;
                    amountBG++;
                    saveLD -= 1;
                    double storeSave = saveOfSave;
                    int storeLD = saveLD;
                    while (storeSave > areaBC && storeLD > 0)
                    {
                        if (dc >= 8)
                        {
                            storeSave -= areaBC;
                            saveAmountBC++;
                            storeLD -= 2;
                        }
                        else
                        {
                            storeSave -= areaBC;
                            saveAmountBC++;
                            storeLD -= 1;
                        }
                    }

                    if (max > storeSave)
                    {
                        max = storeSave;
                        amountBC = saveAmountBC;
                        saveAmountBG = amountBG;
                    }
                    saveAmountBC = 0;
                }
            }
            fprintf(outputFile, "%d %d %.3f", amountBC, saveAmountBG, max);
            fclose(outputFile);
        }
    }
    if (strstr(w, "Rain"))
    {
        while ((save > (areaBC + areaBG)) && ld >= 2)
        {
            if (dc >= 8 && dg >= 5 && ld >= 4)
            {
                save -= (areaBC + areaBG);
                ld -= 4;
                amountBC++;
                amountBG++;
            }
            if (((dc >= 8 && dg < 5) || (dc < 8 && dg >= 5)) && ld >= 3)
            {
                save -= (areaBC + areaBG);
                ld -= 3;
                amountBC++;
                amountBG++;
            }
            if (dc < 8 && dg < 5 && ld >= 2)
            {
                save -= (areaBC + areaBG);
                ld -= 2;
                amountBC++;
                amountBG++;
            }
        }

        if (areaBC > areaBG)
        {
            while (save > areaBC && ld >= 1)
            {
                if (dc >= 8)
                {
                    save -= areaBC;
                    amountBC++;
                    ld -= 2;
                }
                else
                {
                    save -= areaBC;
                    amountBC++;
                    ld -= 1;
                }
            }
        }
        else
        {
            while (save > areaBG && ld >= 1)
            {
                if (dc >= 8)
                {
                    save -= areaBG;
                    amountBG++;
                    ld -= 2;
                }
                else
                {
                    save -= areaBG;
                    amountBG++;
                    ld -= 1;
                }
            }
        }

        fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
        fclose(outputFile);
    }
    if (strstr(w, "Sun"))
    {
        int G = dc % 6;
        int H = ld % 5;
        int arr[5][6] = {
            {5, 7, 10, 12, 15, 20},
            {20, 5, 7, 10, 12, 15},
            {15, 20, 5, 7, 10, 12},
            {12, 15, 20, 5, 7, 10},
            {10, 12, 15, 20, 5, 7}};
        int X = arr[H][G];
        double Rice = (1 + (double)X / 100) * save;
        if ((Rice - (int)Rice) > 0.99888)
        {
            save = (int)Rice;
        }
        else
        {
            save = (int)Rice;
        }
        ld -= X;
        printf("save: %f", save);
        int weatherSub = (dc + dg) % 3;
        if (ld < 0)
        {
            fprintf(outputFile, "-1 -1 %.3f", save);
            fclose(outputFile);
            return 0;
        }
        if (weatherSub == 0)
        {
            // Rain
            while ((save > (areaBC + areaBG)) && ld >= 2)
            {
                if (dc >= 8 && dg >= 5 && ld >= 4)
                {
                    save -= (areaBC + areaBG);
                    ld -= 4;
                    amountBC++;
                    amountBG++;
                }
                if (((dc >= 8 && dg < 5) || (dc < 8 && dg >= 5)) && ld >= 3)
                {
                    save -= (areaBC + areaBG);
                    ld -= 3;
                    amountBC++;
                    amountBG++;
                }
                if (dc < 8 && dg < 5 && ld >= 2)
                {
                    save -= (areaBC + areaBG);
                    ld -= 2;
                    amountBC++;
                    amountBG++;
                }
            }

            if (areaBC > areaBG)
            {
                while (save > areaBC && ld >= 1)
                {
                    if (dc >= 8)
                    {
                        save -= areaBC;
                        amountBC++;
                        ld -= 2;
                    }
                    else
                    {
                        save -= areaBC;
                        amountBC++;
                        ld -= 1;
                    }
                }
            }
            else
            {
                while (save > areaBG && ld >= 1)
                {
                    if (dc >= 8)
                    {
                        save -= areaBG;
                        amountBG++;
                        ld -= 2;
                    }
                    else
                    {
                        save -= areaBG;
                        amountBG++;
                        ld -= 1;
                    }
                }
            }

            fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
            fclose(outputFile);
        }
        if (weatherSub == 1)
        {
            // Wind
            double saveOfSave = save;
            int saveLD = ld;
            int worstCase = 0;
            while (save > areaBC && ld >= 1)
            {
                if (dc >= 8)
                {
                    if (ld >= 2)
                    {
                        amountBC++;
                        save -= areaBC;
                        ld -= 2;
                    }
                    if ((ld <= 1) && save > areaBC)
                    {
                        worstCase = 1;
                        break;
                    }
                }
                else
                {
                    if (ld >= 1)
                    {
                        amountBC++;
                        save -= areaBC;
                        ld -= 1;
                    }
                    if ((ld == 0) && save > areaBC)
                    {
                        worstCase = 1;
                    }
                }
            }
            while (save > areaBG && ld >= 1)
            {
                if (dg >= 5)
                {
                    if (ld >= 2)
                    {
                        amountBG++;
                        save -= areaBG;
                        ld -= 2;
                    }
                    if (ld == 1)
                        break;
                }
                else
                {
                    if (ld >= 1)
                    {
                        amountBG++;
                        save -= areaBG;
                        ld -= 1;
                    }
                }
            }

            if (worstCase == 0 || (worstCase == 1 && areaBG < areaBC))
            {
                fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
                fclose(outputFile);
            }

            if (worstCase == 1 && areaBG > areaBC)
            {
                double max = 99999;

                int saveAmountBG = 0;
                int saveAmountBC = 0;

                while (saveOfSave > areaBG && saveLD > 0)
                {

                    if (dg >= 5)
                    {
                        saveOfSave -= areaBG;
                        amountBG++;
                        saveLD -= 2;

                        double storeSave = saveOfSave;
                        int storeLD = saveLD;
                        while (storeSave > areaBC && storeLD > 0)
                        {
                            if (dc >= 8)
                            {
                                storeSave -= areaBC;
                                saveAmountBC++;
                                storeLD -= 2;
                            }
                            else
                            {
                                storeSave -= areaBC;
                                saveAmountBC++;
                                storeLD -= 1;
                            }
                        }

                        if (max > storeSave)
                        {
                            max = storeSave;
                            amountBC = saveAmountBC;
                            saveAmountBG = amountBG;
                        }
                        saveAmountBC = 0;
                    }
                    else
                    {
                        saveOfSave -= areaBG;
                        amountBG++;
                        saveLD -= 1;
                        double storeSave = saveOfSave;
                        int storeLD = saveLD;
                        while (storeSave > areaBC && storeLD > 0)
                        {
                            if (dc >= 8)
                            {
                                storeSave -= areaBC;
                                saveAmountBC++;
                                storeLD -= 2;
                            }
                            else
                            {
                                storeSave -= areaBC;
                                saveAmountBC++;
                                storeLD -= 1;
                            }
                        }

                        if (max > storeSave)
                        {
                            max = storeSave;
                            amountBC = saveAmountBC;
                            saveAmountBG = amountBG;
                        }
                        saveAmountBC = 0;
                    }
                }
                fprintf(outputFile, "%d %d %.3f", amountBC, saveAmountBG, max);
                fclose(outputFile);
            }
        }
        if (weatherSub == 2)
        {
            // Cloud
            if (checkFriendNum(dc, dg) || checkFriendNum(dg, dc))
            {
                fprintf(outputFile, "0 0 %.3f", save);
                fclose(outputFile);
            }
            else
            {
                double saveOfSave = save;
                int saveLD = ld;
                int worstCase = 0;
                while (save > areaBG && ld >= 1)
                {

                    if (dg >= 5)
                    {
                        if (ld >= 2)
                        {
                            amountBG++;
                            save -= areaBG;
                        }
                        if ((ld <= 0 || ld == 1) && save > areaBG)
                        {
                            worstCase = 1;
                        }
                        if (ld == 1)
                        {
                            break;
                        }
                        ld -= 2;
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            amountBG++;
                            save -= areaBG;
                        }
                        if ((ld <= 0 || ld == 1) && save > areaBG)
                        {
                            worstCase = 1;
                        }
                        if (ld == 1)
                        {
                            break;
                        }
                        ld -= 1;
                    }
                }
                while (save > areaBC && ld >= 1)
                {
                    if (dc >= 8)
                    {
                        if (ld >= 2)
                        {
                            amountBC++;
                            save -= areaBC;
                        }
                        ld -= 2;
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            amountBC++;
                            save -= areaBC;
                        }
                        ld -= 1;
                    }
                }

                if (worstCase == 0 || (worstCase == 1 && areaBC < areaBG))
                {
                    fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
                    fclose(outputFile);
                }
                if (worstCase == 1 && areaBC > areaBG)
                {
                    double max = 99999;
                    int saveAmountBG = 0;
                    int saveAmountBC = 0;
                    amountBC = 0;
                    amountBG = 0;
                    while (saveOfSave > areaBC && saveLD > 0)
                    {
                        if (dc >= 8)
                        {
                            saveOfSave -= areaBC;
                            amountBC++;
                            saveLD -= 2;
                            double storeSave = saveOfSave;
                            int storeLD = saveLD;
                            while (storeSave > areaBG && storeLD > 0)
                            {
                                if (dg >= 5)
                                {
                                    storeSave -= areaBG;
                                    saveAmountBG++;
                                    storeLD -= 2;
                                }
                                else
                                {
                                    storeSave -= areaBG;
                                    saveAmountBG++;
                                    storeLD -= 1;
                                }
                            }

                            if (max > storeSave)
                            {
                                max = storeSave;
                                amountBG = saveAmountBG;
                                saveAmountBC = amountBC;
                            }
                            // storeSave = saveOfSave;
                            // storeLD = saveLD;
                            saveAmountBG = 0;
                        }
                        else
                        {
                            saveOfSave -= areaBC;
                            amountBC++;
                            saveLD -= 1;
                            double storeSave = saveOfSave;
                            int storeLD = saveLD;
                            while (storeSave > areaBG && storeLD > 0)
                            {
                                if (dg >= 5)
                                {
                                    storeSave -= areaBG;
                                    saveAmountBG++;
                                    storeLD -= 2;
                                }
                                else
                                {
                                    storeSave -= areaBG;
                                    saveAmountBG++;
                                    storeLD -= 1;
                                }
                            }

                            if (max > storeSave)
                            {
                                max = storeSave;
                                amountBG = saveAmountBG;
                                saveAmountBC = amountBC;
                            }
                            saveAmountBG = 0;
                        }
                    }
                    fprintf(outputFile, "%d %d %.3f", saveAmountBC, amountBG, max);
                    fclose(outputFile);
                }
            }
        }
    }
    if (strstr(w, "Fog"))
    {
        int dcFake;
        int dgFake;
        if (checkFibo(dc) && checkFibo(dg))
        {
            dcFake = dc / 2;
            dgFake = dg / 2;
            if (dcFake == 0)
            {
                areaBC = 0;
            }
            else
            {
                areaBC = (double)dcFake * dcFake * sqrt(dcFake);
            }
            if (dgFake == 0)
            {
                areaBG = 0;
            }
            else
            {
                areaBG = (double)dgFake * dgFake * PI / 3;
            }
            if (areaBC == 0 && areaBG == 0)
            {
                fprintf(outputFile, "-1 -1 %d", n);
                fclose(outputFile);
                return 0;
            }
            if (areaBC > areaBG)
            {
                while (save > areaBC && ld > 0)
                {
                    if (dcFake >= 8)
                    {
                        if (ld >= 2)
                        {
                            save -= areaBC;
                            amountBC++;
                        }
                        ld -= 2;
                        if (ld == 1 && save > areaBC)
                        {
                            break;
                        }
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            save -= areaBC;
                            amountBC++;
                        }
                        ld -= 1;
                    }
                }
                if (areaBG == 0)
                {
                    fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
                    fclose(outputFile);
                    return 0;
                }
                while (save > areaBG && ld > 0)
                {
                    if (dgFake >= 5)
                    {
                        if (ld >= 2)
                        {
                            save -= areaBG;
                            amountBG++;
                        }
                        ld -= 2;
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            save -= areaBG;
                            amountBG++;
                        }
                        ld -= 1;
                    }
                }
            }
            else
            {
                while (save > areaBG && ld > 0)
                {
                    if (dgFake >= 5)
                    {
                        if (ld >= 2)
                        {
                            save -= areaBG;
                            amountBG++;
                        }
                        ld -= 2;
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            save -= areaBG;
                            amountBG++;
                        }
                        ld -= 1;
                    }
                }
                if (areaBC == 0)
                {
                    fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
                    fclose(outputFile);
                    return 0;
                }
                while (save > areaBC && ld > 0)
                {
                    if (dcFake >= 8)
                    {
                        if (ld >= 2)
                        {
                            save -= areaBC;
                            amountBC++;
                        }
                        ld -= 2;
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            save -= areaBC;
                            amountBC++;
                        }
                        ld -= 1;
                    }
                }
            }
        }
        else
        {
            dcFake = dc * 2;
            dgFake = dg * 2;

            areaBC = dcFake * dcFake * sqrt(dcFake);
            areaBG = dgFake * dgFake * PI / 3;

            if (areaBC > areaBG)
            {
                while (save > areaBC && ld > 0)
                {
                    if (dc >= 8)
                    {
                        if (ld >= 2)
                        {
                            save -= areaBC;
                            amountBC++;
                        }
                        ld -= 2;
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            save -= areaBC;
                            amountBC++;
                        }
                        ld -= 1;
                    }
                }
                while (save > areaBG && ld > 0)
                {
                    if (dg >= 5)
                    {
                        if (ld >= 2)
                        {
                            save -= areaBG;
                            amountBG++;
                        }
                        ld -= 2;
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            save -= areaBG;
                            amountBG++;
                        }
                        ld -= 1;
                    }
                }
            }
            else
            {
                while (save > areaBG && ld > 0)
                {
                    if (dg >= 5)
                    {
                        if (ld >= 2)
                        {
                            save -= areaBG;
                            amountBG++;
                        }
                        ld -= 2;
                        if (ld == 1 && save > areaBG)
                        {
                            break;
                        }
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            save -= areaBG;
                            amountBG++;
                        }
                        ld -= 1;
                    }
                }
                while (save > areaBC && ld > 0)
                {
                    if (dc >= 8)
                    {
                        if (ld >= 2)
                        {
                            save -= areaBC;
                            amountBC++;
                        }
                        ld -= 2;
                    }
                    else
                    {
                        if (ld >= 1)
                        {
                            save -= areaBC;
                            amountBC++;
                        }
                        ld -= 1;
                    }
                }
            }
        }
        fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
        fclose(outputFile);
    }
    if (strstr(w, "Cloud"))
    {
        if (checkFriendNum(dc, dg) || checkFriendNum(dg, dc))
        {
            fprintf(outputFile, "0 0 %.3f", save);
            fclose(outputFile);
        }
        else
        {
            double saveOfSave = save;
            int saveLD = ld;
            int worstCase = 0;
            while (save > areaBG && ld >= 1)
            {
                if (dg >= 5)
                {
                    if (ld >= 2)
                    {
                        amountBG++;
                        save -= areaBG;
                    }
                    if ((ld <= 0 || ld == 1) && save > areaBG)
                    {
                        worstCase = 1;
                    }
                    if (ld == 1)
                    {
                        break;
                    }
                    ld -= 2;
                }
                else
                {
                    if (ld >= 1)
                    {
                        amountBG++;
                        save -= areaBG;
                    }
                    if ((ld <= 0 || ld == 1) && save > areaBG)
                    {
                        worstCase = 1;
                    }
                    if (ld == 1)
                    {
                        break;
                    }
                    ld -= 1;
                }
            }
            while (save > areaBC && ld >= 1)
            {
                if (dc >= 8)
                {
                    if (ld >= 2)
                    {
                        amountBC++;
                        save -= areaBC;
                    }
                    ld -= 2;
                }
                else
                {
                    if (ld >= 1)
                    {
                        amountBC++;
                        save -= areaBC;
                    }
                    ld -= 1;
                }
            }

            if (worstCase == 0 || (worstCase == 1 && areaBC < areaBG))
            {
                fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
                fclose(outputFile);
            }
            if (worstCase == 1 && areaBC > areaBG)
            {
                double max = 99999;
                int saveAmountBG = 0;
                int saveAmountBC = 0;
                amountBC = 0;
                amountBG = 0;
                while (saveOfSave > areaBC && saveLD > 0)
                {

                    if (dc >= 8)
                    {
                        saveOfSave -= areaBC;
                        amountBC++;
                        saveLD -= 2;
                        double storeSave = saveOfSave;
                        int storeLD = saveLD;
                        while (storeSave > areaBG && storeLD > 0)
                        {
                            if (dg >= 5)
                            {
                                storeSave -= areaBG;
                                saveAmountBG++;
                                storeLD -= 2;
                            }
                            else
                            {
                                storeSave -= areaBG;
                                saveAmountBG++;
                                storeLD -= 1;
                            }
                        }

                        if (max > storeSave)
                        {
                            max = storeSave;
                            amountBG = saveAmountBG;
                            saveAmountBC = amountBC;
                        }
                        // storeSave = saveOfSave;
                        // storeLD = saveLD;
                        saveAmountBG = 0;
                    }
                    else
                    {
                        saveOfSave -= areaBC;
                        amountBC++;
                        saveLD -= 1;
                        double storeSave = saveOfSave;
                        int storeLD = saveLD;
                        while (storeSave > areaBG && storeLD > 0)
                        {
                            if (dg >= 5)
                            {
                                storeSave -= areaBG;
                                saveAmountBG++;
                                storeLD -= 2;
                            }
                            else
                            {
                                storeSave -= areaBG;
                                saveAmountBG++;
                                storeLD -= 1;
                            }
                        }

                        if (max > storeSave)
                        {
                            max = storeSave;
                            amountBG = saveAmountBG;
                            saveAmountBC = amountBC;
                        }
                        saveAmountBG = 0;
                    }
                }
                fprintf(outputFile, "%d %d %.3f", saveAmountBC, amountBG, max);
                fclose(outputFile);
            }
        }
    }

    return 0;
}
