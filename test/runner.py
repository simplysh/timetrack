import subprocess
import os
import sys

timetrack = os.path.abspath('../timetrack')

if (sys.platform == 'windows'):
  timetrack = os.path.abspath('../timetrack.exe')

def run(args=[]):
  stdout = subprocess.check_output([timetrack] + args).decode('UTF-8').replace('\r', '')
  f = open(args[0], 'r')
  result = f.read()
  f.close()

  return (stdout, result)