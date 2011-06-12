# Design

## Implementation overview
- Find all class declarations from `CG(class_table)`
- Override `ce->object_new` with `php_classresolver_object_new()`
- Store old `ce->object_new` in `CG(object_new)`
- Custom `create_object` handler:
  - If class resolver is registered, resolve class name with `Class\Resolver::resolve()`
    - Retrieve related class entry
	- Return `zend_object_value` with new class entry
  - If configurator is registered, pass original constructor parameters and classname to `Class\Configurator::preConstruct()`

## Userland API
```php
<?php
namespace Class;
interface Resolver
{
    string public function resolve(string $runtimeClassName);
}

interface Configurator
{
    array public function preConstruct(string $runtimeClassName, array $runtimeConstructorArguments);

    void public function postConstruct(string $runtimeClassName, object $object);
}

function register_resolver(Resolver $resolver);

function register_configurator(Configurator $configurator);
```

### Example 1: Rewrite class
```php
<?php
class myStdClass extends stdClass
{
}

class stdClassResolver implements Class\Resolver
{
    public function resolve($runtimeClassName)
    {
        switch ($runtimeClassName) {
            case 'stdClass':
                return 'myStdClass';
                break;

            default:
                return $runtimeClassName;
                break;
        }
    }
}
```
