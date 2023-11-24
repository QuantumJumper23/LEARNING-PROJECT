#include<iostream>
#include<vector>
#include<chrono>
#include<thread>
#include<random>
void printgrid(std::vector<std::vector<bool>>&grid)
{
for(auto& row:grid)
{
    for(bool cell:row)
    {
        std::cout<<(cell? "#":" ");
    }
    std::cout<<std::endl;

}
}
void updategrid(std::vector<std::vector<bool>>&grid)
{
    int row=grid.size();//checking row in vector
    int column=grid[0].size();//checking column in vector
     std::vector<std::vector<bool>> newGrid(row, std::vector<bool>(column, false));//column false
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        
        {int neighbours=0;
            for(int ne=-1;ne<=1;ne++)
            {
                for(int ni=-1;ni<=1;ni++)
                {
                    if(ne==0&&ni==0)
                    continue;
                 auto ne_=i+ne;
                 auto ni_=j+ni;
                    

                if (ne_ >= 0 && ne_ < row && ni_ >= 0 && ni_ < column) {
                    neighbours = neighbours+(grid[ne_][ni_] ? 1 : 0);  
                }
            }
            }
        if(grid[i][j])
        {
            newGrid[i][j]=(neighbours==2||neighbours==3);
        }
        else{
            newGrid[i][j]=(neighbours==3);
        }
        
        }
        
    }
     grid=newGrid;


}
int main()
{
int row=20;
int column=40;
std::random_device rd;  //random number
std::mt19937 eng(rd());
std::vector<std::vector<bool>>grid(row,std::vector<bool>(column,false));
for(int i=0;i<row;i++)
{
    for(int j=0;j<column;j++)
    {
          std::uniform_int_distribution<> distr(0, 1);
            grid[i][j] = distr(eng) == 1;
    }
}

while(true)
{
    printgrid(grid);
    updategrid(grid);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    system("cls"); 
    
}
return 0;
}