#include "lmt.h"
#include "t_bfs.h"
#include "t_lss.h"
#include "bool.h"
#include "describe.h"

int main(int argc, char **argv)
{
    t_bfs   *p_bfs;
    t_lss   *p_lss;

    if (argc <= 7)
    {
        p_bfs = new_bfs(argc, argv);
        if (bfs_run(p_bfs) == TRUE)
		{
//			while (1);
            return (0);
		}
        free_bfs(p_bfs);
    }
    p_lss = new_lss(argc, argv);
    lss_run(p_lss);
//	while (1);
    return (0);
}
