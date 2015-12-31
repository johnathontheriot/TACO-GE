from pathlib import Path
import os

def main(argv=None):
	p = Path(os.getcwd())
	files = list(p.glob('**/*.h'))
	if os.path.exists('../cpp'):
		for i in files:
			fName = str(i.parts[-1])
			print(fName)
			fName = fName[:-1] + "cpp"
			f = open('../cpp/' + fName, 'a+')
			f.seek(0, 0)
			data = f.read()
			f.write('#include "../h/' + str(i.parts[-1]) + '"\n')	 
			f.write(data)
			f.close()
	else:
		print('No cpp file to match the current directory')
if __name__ == "__main__":
	main()