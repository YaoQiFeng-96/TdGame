#ifndef __TILE_H__
#define __TILE_H__

#include <vector>

#define SIZE_TILE 48

struct  Tile
{
	enum class Direction
	{
		None,
		Up,
		Down,
		Left,
		Right
	};
	int terrian = 0;		//地形
	int decoration = -1;	//装饰
	int special_flag = -1;	//特殊标志
	bool has_tower = false;	//当前是否已放置防御塔
	Direction direction = Direction::None;	//方向
};

typedef std::vector<std::vector<Tile>> TileMap;

#endif // !__TILE_H__
