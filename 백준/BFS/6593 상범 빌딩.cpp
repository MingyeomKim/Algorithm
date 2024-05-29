#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#define endl '\n'
using namespace std;

bool canMove[31][31][31];
int dist[31][31][31];

int dz[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, -1, 0, 0, 1, 0 };
int dx[6] = { 0, 0, 1, 0,  0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		memset(dist, -1, sizeof(dist));
		memset(canMove, false, sizeof(canMove));

		int l, r, c;
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) {
			break;
		}

		tuple<int, int, int> start, end;
		for (int z = 0; z < l; z++) {
			for (int y = 0; y < r; y++) {
				for (int x = 0; x < c; x++) {
					char space; cin >> space;
					if (space == '#') {
						canMove[z][y][x] = false;
					}
					else if (space == '.') {
						canMove[z][y][x] = true;
					}
					else if (space == 'S') {
						start = make_tuple(z, y, x);
						canMove[z][y][x] = true;
					}
					else if (space == 'E') {
						end = make_tuple(z, y, x);
						canMove[z][y][x] = true;
					}
				}
			}
		}

		queue<tuple<int, int, int>> q;
		q.push(start);
		int sy, sx, sz;
		std::tie(sz, sy, sx) = start;
		dist[sz][sy][sx] = 0;
		while (!q.empty()) {
			int y, x, z;
			std::tie(z, y, x) = q.front();
			q.pop();

			for (int dir = 0; dir < 6; dir++) {
				int nz = z + dz[dir];
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || ny >= r || nx < 0 || nx >= c || nz < 0 || nz >= l || dist[nz][ny][nx] != -1 || !canMove[nz][ny][nx]) {
					continue;
				}
				q.push(make_tuple(nz, ny, nx));
				dist[nz][ny][nx] = dist[z][y][x] + 1;
			}
		}

		int ey, ex, ez;
		std::tie(ez, ey, ex) = end;
		if (dist[ez][ey][ex] == -1) {
			cout << "Trapped!" << endl;
		}
		else {
			cout << "Escaped in " << dist[ez][ey][ex] << " minute(s)." << endl;
		}
	}
	return 0;
}