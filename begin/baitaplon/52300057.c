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
    if ((inputFile = fopen("/Users/tsangcuteso1/Beginning/begin/baitaplon/input.inp", "r")) == NULL)
    {
        printf("Khong the mo tap tin input.inp\n");
        perror("Loi khi mo tap tin: ");
        return 0;
    }
    fscanf(inputFile, "%d %d %d %d", &n, &dc, &dg, &ld);

    fgets(w, sizeof(w), inputFile);
    fclose(inputFile);
    if ((outputFile = fopen("/Users/tsangcuteso1/Beginning/begin/baitaplon/output.out", "w")) == NULL)
    {
        printf("Khong the mo tap tin output.out\n");
        return 0;
    }
    if (
        n > 2000 ||
        n <= 0 ||
        dc < 0 ||
        dg < 0 ||
        (ld <= 1 || ld >= 600) ||
        (strstr(w, "Wind") == NULL && strstr(w, "Rain") == NULL && strstr(w, "Sun") == NULL && strstr(w, "Cloud") == NULL && strstr(w, "Fog") == NULL))
    {
        fprintf(outputFile, "-1 -1 %d", n);
        fclose(outputFile);
    }
    float save = n;
    float areaBC = (float)dc * dc * sqrt(dc);
    float areaBG = (float)dg * dg * PI / 3;
    int amountBC = 0;
    int amountBG = 0;
    if (strstr(w, "Wind"))
    {
        float saveOfSave = save;
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
                }

                if ((ld <= 0 || ld == 1) && save > areaBC)
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
                    amountBC++;
                    save -= areaBC;
                }
                if ((ld <= 0 || ld == 1) && save > areaBC)
                {
                    worstCase = 1;
                }
                ld -= 1;
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
                ld -= 1;
            }
        }

        if (worstCase == 0 || (worstCase == 1 && areaBG < areaBC))
        {
            fprintf(outputFile, "%d %d %.3f", amountBC, amountBG, save);
            fclose(outputFile);
        }
        if (worstCase == 1 && areaBG > areaBC)
        {
            float max = 99999;

            int saveAmountBG = 0;
            int saveAmountBC = 0;
            while (saveOfSave > areaBG && saveLD > 0)
            {

                if (dg >= 5)
                {
                    saveOfSave -= areaBG;
                    amountBG++;
                    saveLD -= 2;
                    float storeSave = saveOfSave;
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
                    // storeSave = saveOfSave;
                    // storeLD = saveLD;
                    saveAmountBC = 0;
                }
                else
                {
                    saveOfSave -= areaBG;
                    amountBG++;
                    saveLD -= 1;
                    int storeSave = saveOfSave;
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

        // while (save > areaBC && ld >= 1)
        // {
        //     if (dc >= 8)
        //     {
        //         if (ld == 1)
        //         {
        //             break;
        //         }
        //         if (ld == 2 && areaBG > areaBC && save - areaBG > 0)
        //         {
        //             break;
        //         }
        //     }
        //     amountBC++;
        //     save -= areaBC;

        //     if (dc >= 8)
        //     {
        //         ld -= 2;
        //     }
        //     else
        //     {
        //         ld -= 1;
        //     }
        // }
        // while (save > areaBG && ld >= 1)
        // {
        //     if (dg >= 5)
        //     {
        //         if (ld == 1)
        //         {
        //             break;
        //         }
        //         if (ld == 2 && areaBG > areaBC && save - areaBG > 0)
        //         {
        //             save -= areaBG;
        //             amountBG++;
        //             ld -= 2;
        //             break;
        //         }
        //     }
        //     if (ld == 1)
        //     {
        //         save -= areaBG;
        //         amountBG++;
        //         ld -= 1;
        //         break;
        //     }
        //     save -= areaBG;
        //     amountBG++;
        //     if (dg >= 5)
        //     {
        //         ld -= 2;
        //     }
        //     else
        //     {
        //         ld -= 1;
        //     }
        // }
    }
    if (strstr(w, "Rain"))
    {
        while ((save > (areaBC + areaBG)) && ld >= 2)
        {
            if (dc >= 8 && dg >= 5 && (ld == 3 || ld == 2))
            {
                if (areaBC > areaBG)
                {
                    save -= areaBC;
                    amountBC++;
                    ld -= 2;
                    break;
                }
                else
                {
                    save -= areaBG;
                    amountBG++;
                    ld -= 2;
                    break;
                }
            }

            if (ld == 2)
            {
                int saveValueBC = save;
                int saveValueBG = save;
                int saveAmountBC = 0;
                int saveAmountBG = 0;
                if (dc >= 8)
                {
                    saveValueBC -= areaBC;
                    saveAmountBC++;

                    while (ld > 0)
                    {
                        saveValueBG -= areaBG;
                        saveAmountBG++;
                        ld--;
                    }

                    if (saveValueBC > saveValueBG)
                    {
                        amountBC += saveAmountBC;
                        save = saveValueBC;
                    }
                    else
                    {
                        amountBG += saveAmountBG;
                        save = saveValueBG;
                    }
                }
                if (dg >= 5)
                {
                    saveValueBG -= areaBG;
                    saveAmountBG++;

                    while (ld > 0)
                    {
                        saveValueBC -= areaBC;
                        saveAmountBC++;
                        ld--;
                    }

                    if (saveValueBG > saveValueBC)
                    {
                        amountBG += saveAmountBG;
                        save = saveValueBG;
                    }
                    else
                    {
                        amountBC += saveAmountBC;
                        save = saveValueBC;
                    }
                }
            }

            save -= areaBC;
            save -= areaBG;
            amountBC++;
            amountBG++;
            if (dc >= 8)
            {
                ld -= 2;
            }
            else
            {
                ld -= 1;
            }
            if (dg >= 5)
            {
                ld -= 2;
            }
            else
            {
                ld -= 1;
            }
        }

        if (ld >= 1)
        {
            int subBC = 0;
            int subBG = 0;
            float saveValueBC = save;
            float saveValueBG = save;

            while (saveValueBC - areaBC > 0 && ld > 0)
            {
                saveValueBC -= areaBC;
                subBC++;
                if (dc >= 8)
                {
                    ld -= 2;
                }
                else
                {
                    ld -= 1;
                }
            }
            while (saveValueBG - areaBG > 0 && ld > 0)
            {
                saveValueBG -= areaBG;
                subBG++;
                if (dg >= 5)
                {
                    ld -= 2;
                }
                else
                {
                    ld -= 1;
                }
            }
            if (saveValueBC < saveValueBG)
            {
                save = saveValueBC;
                amountBC += subBC;
            }
            else
            {
                save = saveValueBG;
                amountBG += subBG;
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
        float Rice = (1 + (float)X / 100) * save;
        char weather[10];
        int weatherSub = (dc + dg) % 3;
        if (weatherSub == 0)
        {
            strcpy(weather, "Rain");
        }
        if (weatherSub == 1)
        {
            strcpy(weather, "Wind");
        }
        else
        {
            strcpy(weather, "Cloud");
        }
        fprintf(outputFile, "%.0f %d %d %d %s", round(Rice), dc, dg, ld - X, weather);
        fclose(outputFile);
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
                areaBC = (float)dcFake * dcFake * sqrt(dcFake);
            }
            if (dgFake == 0)
            {
                areaBG = 0;
            }
            else
            {
                areaBG = (float)dgFake * dgFake * PI / 3;
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
                        if( ld == 1 && save > areaBC){
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
                        if(ld == 1 && save > areaBG){
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
            fprintf(outputFile, "0 0 %d", n);
            fclose(outputFile);
        }
        else
        {

            int saveOfSave = save;
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
                float max = 99999;

                int saveAmountBG = 0;
                int saveAmountBC = 0;
                while (saveOfSave > areaBC && saveLD > 0)
                {

                    if (dc >= 8)
                    {
                        saveOfSave -= areaBC;
                        amountBC++;
                        saveLD -= 2;
                        float storeSave = saveOfSave;
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
                        int storeSave = saveOfSave;
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
                fprintf(outputFile, "%d %d %.3f", saveAmountBC, saveAmountBG, max);
                fclose(outputFile);
            }
        }
    }
    return 0;
}
