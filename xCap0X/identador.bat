@echo off
for /r %%f in (*.cpp *.hpp *.h) do (
    echo Formatting %%f
    clang-format -style=microsoft -i "%%f"
)
echo Formatting complete.
