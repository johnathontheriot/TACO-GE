from pathlib import Path

def main(argv=None):
	p = Path('usr/scripts')
	files = list(p.glob('**/*.h'))
	f = open('main.cpp', 'r+')
	current_main = f.read()
	f.seek(0, 0)
	for i in files:
		f.write('#include "' + str(i) + '"\n')	 
	f.write(current_main)

if __name__ == "__main__":
	main()