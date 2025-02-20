from setuptools import find_packages
from setuptools import setup

setup(
    name='offboard_ros2',
    version='0.0.0',
    packages=find_packages(
        include=('offboard_ros2', 'offboard_ros2.*')),
)
