class Solution {
public:
    int MAX_WIDTH;

    string findLine(int i, int j, int eachSpace, int extraSpace, vector<string>& words)
    {
        string line;

        for(int k = i; k < j; k++)
        {
            line += words[k];
            if(k == j - 1) continue;

            for(int z = 1; z <= eachSpace; z++) line += " ";

            if(extraSpace > 0)
            {
                line += " ";
                extraSpace--;
            }
        }
        while(line.length() < MAX_WIDTH) line += " ";
        return line;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        int i = 0;
        int n = words.size();

        MAX_WIDTH = maxWidth;

        while(i < n)
        {
            int lettersCount = words[i].length();
            int j = i + 1, spaceSlot = 0;

            while(j < n && lettersCount + spaceSlot + words[j].length() + 1 <= maxWidth)
            {
                lettersCount += words[j].length(); 
                spaceSlot += 1;
                j++;  
            }

            int remainingSlot = maxWidth - lettersCount;

            int eachWordSpace = spaceSlot == 0 ? 0 : remainingSlot / spaceSlot;
            int extraSpace =  spaceSlot == 0 ? 0 : remainingSlot % spaceSlot;

            if(j == n)
            {
                eachWordSpace = 1;
                extraSpace = 0;
            }
            result.push_back(findLine(i, j, eachWordSpace, extraSpace, words));
            i = j;
        }
        return result;
    }
};